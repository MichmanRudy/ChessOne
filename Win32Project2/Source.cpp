#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include"resource.h"
#include"Field.h"






#pragma region ID

#define ID_ONE 10




#pragma endregion

int TranslateIJtoK(int i,int j)
{
	int ReturnValue;
	ReturnValue = (i + 1) * 10 + j + 1;
	return ReturnValue;

}

int GetBitmapsImageIngex(Field UsersField,int Position)
{
	return UsersField.GetDeskValue(Position);
}

void DeskRefresh(Field UsersField, HWND hWnd, HINSTANCE hInstance)
{
	HBITMAP hBitmap[28] =
	{
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_W),	//0
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_W),	//1
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_B),	//2
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_B),	//3
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_B),	//4
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_W),	//5
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_B),	//6
		LoadBitmap(hInstance, (LPCWSTR)KING_B_W),	//7
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_B),	//8
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_W),	//9
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_B),	//10
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_W),	//11
		LoadBitmap(hInstance, (LPCWSTR)KING_B_B),	//12
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_W),	//13
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_W),	//14
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_B),	//15
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_W),	//16
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_B),	//17
		LoadBitmap(hInstance, (LPCWSTR)KING_W_W),	//18
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_B),	//19
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_W),	//20
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_B),	//21
		LoadBitmap(hInstance, (LPCWSTR)KING_W_B),	//22
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_W),	//23
		LoadBitmap(hInstance, (LPCWSTR)WHITE),	//24
		LoadBitmap(hInstance, (LPCWSTR)BLACK)	//25
	};

	LPCTSTR  Labels[9] =
	{
		L"A",
		L"B",
		L"C",
		L"D",
		L"E",
		L"F",
		L"G",
		L"H"
	};
	LPCTSTR  Numbers[9] =
	{
		L"1",
		L"2",
		L"3",
		L"4",
		L"5",
		L"6",
		L"7",
		L"8"
	};

	for (int i = 0, k = 0, c = 9; i < 10; i++, c--)
	{
		for (int j = 0, h = 9; j < 10; j++, k++, h--)
		{

			/*		HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"text", WS_VISIBLE | WS_CHILD ,
			0 + i * 60,
			0+j*60,
			60,
			60,
			hWnd, (HMENU)k, hInstance, 0);
			SetDlgItemText(hWnd, k, L"1");*/
			if (k <= 9 || k >= 90)			//top and bottom rows with A-H labels
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);

				if (i == 9) SetDlgItemText(hWnd, k, Labels[j - 1]);		//assign labels
				if (i == 0) SetDlgItemText(hWnd, k, Labels[h - 1]);		//assign labels
			}
			else if (j == 0 || j == 9)//side numbers
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);

				if (j == 9) SetDlgItemText(hWnd, k, Numbers[i - 1]);	//assign numbers
				if (j == 0) SetDlgItemText(hWnd, k, Numbers[c - 1]);	//assign numbers
			}
			else if (2 < i&&i < 7) // clear nodes
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);
				if (i % 2 != 0)
				{
					if (k % 2 != 0)SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[25]);
					else SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[24]);
				}
				else
				{
					if (k % 2 != 0)SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[24]);
					else SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[25]);
				}

			}

			else if (i == 2) // pishky blk
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);
				if (j % 2 != 0) SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[1]);
				else  SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[3]);
			}
			else if (i == 7) // pishky wht
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);
				if (j % 2 != 0) SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[2]);
				else  SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[0]);
			}
			else if (i == 1) // figures blk
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);
				SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[4 + j - 1]);

			}
			else if (i == 8) // pishky wht
			{
				HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
					0 + j * 60,
					0 + i * 60,
					60,
					60,
					hWnd, (HMENU)k, hInstance, 0);
				SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[14 + j - 1]);

			}
		}

	}



}


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

Field ChessField1;



void RedrawField(HWND hWnd, HINSTANCE hInstance)
{
	HBITMAP hBitmap[28] =
	{
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_W),	//0
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_W),	//1
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_B),	//2
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_B),	//3
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_B),	//4
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_W),	//5
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_B),	//6
		LoadBitmap(hInstance, (LPCWSTR)KING_B_W),	//7
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_B),	//8
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_W),	//9
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_B),	//10
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_W),	//11
		LoadBitmap(hInstance, (LPCWSTR)KING_B_B),	//12
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_W),	//13
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_W),	//14
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_B),	//15
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_W),	//16
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_B),	//17
		LoadBitmap(hInstance, (LPCWSTR)KING_W_W),	//18
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_B),	//19
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_W),	//20
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_B),	//21
		LoadBitmap(hInstance, (LPCWSTR)KING_W_B),	//22
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_W),	//23
		LoadBitmap(hInstance, (LPCWSTR)WHITE),	//24
		LoadBitmap(hInstance, (LPCWSTR)BLACK)	//25
	};

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			SendMessage(GetDlgItem(hWnd, TranslateIJtoK(i, j)), BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[ChessField1.GetDeskValue(TranslateIJtoK(i, j))]);
		}
	}
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
#pragma region WindowClass
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.lpfnWndProc = WinProc;
	wcl.hInstance = hInstance;
	wcl.style = CS_HREDRAW, CS_VREDRAW;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)(16);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = L"ClName";
	if (!RegisterClassEx(&wcl))
	{
		return 0;
	}
#pragma endregion
#pragma region items



	HWND hWnd = CreateWindowEx(0, wcl.lpszClassName, L"Chess", WS_SYSMENU,
		100, 
		100, 
		615, 
		640,
		0, 0, hInstance, 0);

/*
	HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP ,
			0,
			540,
			60,
			60,
			hWnd, (HMENU)ID_ONE, hInstance, 0);
//	}
		
		
		HBITMAP hBitmap;
		hBitmap = LoadBitmap(hInstance, (LPCWSTR)PISH_W_W);
		SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
*/	
	HBITMAP hBitmap[28]=
	{
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_W),	//0
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_W),	//1
		LoadBitmap(hInstance, (LPCWSTR)PISH_W_B),	//2
		LoadBitmap(hInstance, (LPCWSTR)PISH_B_B),	//3
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_B),	//4
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_W),	//5
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_B),	//6
		LoadBitmap(hInstance, (LPCWSTR)KING_B_W),	//7
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_B),	//8
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_B_W),	//9
		LoadBitmap(hInstance, (LPCWSTR)HORSE_B_B),	//10
		LoadBitmap(hInstance, (LPCWSTR)SLON_B_W),	//11
		LoadBitmap(hInstance, (LPCWSTR)KING_B_B),	//12
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_B_W),	//13
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_W),	//14
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_B),	//15
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_W),	//16
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_B),	//17
		LoadBitmap(hInstance, (LPCWSTR)KING_W_W),	//18
		LoadBitmap(hInstance, (LPCWSTR)OFFICER_W_B),	//19
		LoadBitmap(hInstance, (LPCWSTR)HORSE_W_W),	//20
		LoadBitmap(hInstance, (LPCWSTR)SLON_W_B),	//21
		LoadBitmap(hInstance, (LPCWSTR)KING_W_B),	//22
		LoadBitmap(hInstance, (LPCWSTR)QUEEN_W_W),	//23
		LoadBitmap(hInstance, (LPCWSTR)WHITE),	//24
		LoadBitmap(hInstance, (LPCWSTR)BLACK)	//25
	};

	LPCTSTR  Labels[9] =
	{
		L"A",
		L"B",
		L"C",
		L"D",
		L"E",
		L"F",
		L"G",
		L"H"
	};
	LPCTSTR  Numbers[9] =
	{
		L"1",
		L"2",
		L"3",
		L"4",
		L"5",
		L"6",
		L"7",
		L"8"
	};
//	SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)WHITE);
	
	for (int i = 0,k=0,c=9; i < 10; i++,c--)
		{
			for (int j = 0,h=9; j < 10; j++, k++,h--)
			{
				
		
				if (k<=9 || k >= 90)			//top and bottom rows with A-H labels
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
				
					if (i==9) SetDlgItemText(hWnd, k, Labels[j-1]);		//assign labels
					if (i==0) SetDlgItemText(hWnd, k, Labels[h-1]);		//assign labels
				}
				else if (j==0 || j == 9)//side numbers
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);

					if (j == 9 ) SetDlgItemText(hWnd, k, Numbers[i-1]);	//assign numbers
					if (j == 0) SetDlgItemText(hWnd, k, Numbers[c-1]);	//assign numbers
				}
				else if (2 < i&&i < 7) // clear nodes
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
					if (i % 2 != 0)
					{
						if (k % 2 != 0)SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[25]);
						else SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[24]);
					}
					else
					{
						if (k % 2 != 0)SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[24]);
						else SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[25]);
					}

				}

				else if (i == 2) // pishky blk
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
					if (j % 2 != 0) SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[1]);
					else  SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[3]);
				}
				else if (i == 7) // pishky wht
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
					if (j % 2 != 0) SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[2]);
					else  SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[0]);
				}
				else if (i == 1) // figures blk
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
					SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[4+j-1]);
					
				}
				else if (i == 8) // pishky wht
				{
					HWND hButton = CreateWindowEx(WS_EX_CLIENTEDGE, L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
						0 + j * 60,
						0 + i * 60,
						60,
						60,
						hWnd, (HMENU)k, hInstance, 0);
					SendMessage(hButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[14+j-1]);
					
				}
			}

		} 
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			SendMessage(GetDlgItem(hWnd, TranslateIJtoK(i,j)), BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[ChessField1.GetDeskValue(TranslateIJtoK(i,j))]);
		}
	}

	//SendMessage(GetDlgItem(hWnd, 87), BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap[25]);

#pragma endregion
#pragma region operations
	ShowWindow(hWnd, cmdShow);
	UpdateWindow(hWnd);
	MSG msg;
	//SetFocus(hCBox1);

	while (GetMessage(&msg, 0, 0, 0))
	{


		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#pragma endregion
	return EXIT_SUCCESS;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	//Field ChessField;
	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(NULL);

	switch (Message)
	{
		
	case WM_PAINT:
	
		
		break;

	case WM_COMMAND:
	





	
		switch (GetDlgCtrlID(GetFocus()))
		{
		

		default:
			break;
		}
	
		switch (HIWORD(wParam))
		{
		case BN_CLICKED:
			if (!ChessField1.GetIsSelected()) ChessField1.SetSelected( LOWORD(wParam));
			else
			{
				ChessField1.SetSelected(LOWORD(wParam));
				ChessField1.SetDesk(LOWORD(wParam));
				RedrawField(hWnd, hInstance);
			}
		

		/*	switch (LOWORD(wParam))
			{
			
				
			default:
				break;
			}*/
			break;
		default:
			break;
		}
	
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:

		return DefWindowProc(hWnd, Message, wParam, lParam);
	}
}

