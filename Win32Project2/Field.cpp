#include "Field.h"


Field::Field()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(i==0)desk[i][j] = 4 + j;
			else if (i == 1)
			{
				if (j % 2==0)desk[i][j] = 1;
				else desk[i][j] = 3;
			}
			else if (i>1 && i < 6)
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)desk[i][j] = 25;
					else desk[i][j] = 24;
				}
				else
				{
					if (j % 2 == 0)desk[i][j] = 24;
					else desk[i][j] = 25;
				}
			}
			else if (i==6)
			{
				if (j % 2 == 0)desk[i][j] = 2;
				else desk[i][j] = 0;
			}
			else if (i == 7)desk[i][j] = 14 + j;
			
		}
		
	}
	IsSelected = false;
	selected.X = 0;
	selected.Y = 0;
	SelectedValue = 0;

}

int Field::GetDeskValue(int Position)
{
	return desk[TranslateKtoIJ(Position).Y][TranslateKtoIJ(Position).X];
}

COORD Field::TranslateKtoIJ(int k)
{
	COORD TemporaryCoord;
	TemporaryCoord.X = k % 10-1;
	TemporaryCoord.Y = k / 10 % 10 - 1;
	return TemporaryCoord;

}

void Field::SetDesk(int k)
{
	int TemporaryValue;
	TemporaryValue = desk[TranslateKtoIJ(k).Y][TranslateKtoIJ(k).X];
	desk[TranslateKtoIJ(k).Y][TranslateKtoIJ(k).X] = SelectedValue;
	desk[selected.Y][selected.X] = TemporaryValue;
	IsSelected = false;

}

void Field::SetSelected(int k)
{
	short iSelected = TranslateKtoIJ(k).Y;
	short jSelected = TranslateKtoIJ(k).X;
	if (IsSelected == false) // no selected yet
	{
		IsSelected = true;
		this->selected.X = jSelected;
		this->selected.Y = iSelected;
		SelectedValue = desk[iSelected][jSelected];
	}
	else if(selected.X == iSelected&&selected.Y == jSelected) // clicked on selected item
	{
		IsSelected = false;
		return;
	}
	
}

bool Field::GetIsSelected()
{
	return IsSelected;
}

bool Field::MovementRulesCheck(int k)
{
	if (SelectedValue < 4) //if pishka
	{
		if (abs(TranslateKtoIJ(k).Y - this->selected.Y) < 3 && TranslateKtoIJ(k).X == this->selected.X) 
			//if selected movement is not more than 2 y steps and X coord is the same
		{
			for (int i = 0; i < abs(TranslateKtoIJ(k).Y - this->selected.Y); i++)
			{
				if (SelectedValue == 0 || SelectedValue == 2) //if white pish
				{
					if (desk[selected.Y - i][selected.X] != 25 && desk[selected.Y - i][selected.X] != 24) return false;
					//if the next one(two) steps are not clear
				}
				if (SelectedValue == 1 || SelectedValue == 3) //if black pish
				{
					if (desk[selected.Y + i][selected.X] != 25 && desk[selected.Y + i][selected.X] != 24) return false;
					//if the next one(two) steps are not clear
				}

			}
			return true;

		}
		else if (abs(TranslateKtoIJ(k).Y - this->selected.Y) == 2 && TranslateKtoIJ(k).X - this->selected.X == 1)
			//if selected movement is diagonal to right - in case of attack
		{
			if (SelectedValue == 0 || SelectedValue == 2) //if white pish
			{
				if (desk[selected.Y - 1][selected.X + 1] != 1 && desk[selected.Y - 1][selected.X + 1] != 3) return false;
				// if right diagonal element is not black pishka
				if (desk[selected.Y - 2][selected.X + 1] != 24 && desk[selected.Y - 2][selected.X + 1] != 25) return false;
				//if right - 2y diagonal element is not empty
			}
			if (SelectedValue == 1 || SelectedValue == 3) //if black pish
			{
				if (desk[selected.Y + 1][selected.X + 1] != 1 && desk[selected.Y + 1][selected.X + 1] != 3) return false;
				// if right diagonal element is not white pishka
				if (desk[selected.Y + 2][selected.X + 1] != 24 && desk[selected.Y + 2][selected.X + 1] != 25) return false;
				//if right - 2y diagonal element is not empty
			}
			return true;
		}
		else if (abs(TranslateKtoIJ(k).Y - this->selected.Y) == 2 && TranslateKtoIJ(k).X - this->selected.X == -1)
			//if selected movement is diagonal to left - in case of attack
		{
			if (SelectedValue == 0 || SelectedValue == 2) //if white pish
			{
				if (desk[selected.Y - 1][selected.X - 1] != 1 && desk[selected.Y - 1][selected.X - 1] != 3) return false;
				// if right diagonal element is not black pishka
				if (desk[selected.Y - 2][selected.X - 1] != 24 && desk[selected.Y - 2][selected.X - 1] != 25) return false;
				//if right - 2y diagonal element is not empty
			}
			if (SelectedValue == 1 || SelectedValue == 3) //if black pish
			{
				if (desk[selected.Y + 1][selected.X - 1] != 1 && desk[selected.Y + 1][selected.X - 1] != 3) return false;
				// if right diagonal element is not white pishka
				if (desk[selected.Y + 2][selected.X - 1] != 24 && desk[selected.Y + 2][selected.X - 1] != 25) return false;
				//if right - 2y diagonal element is not empty
			}
			return true;
		}

		
		else return false;
	}
	
}

Field::~Field()
{
}
