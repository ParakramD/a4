/* a4_1.cpp Parakram Dahal
Dave Harden CS10B
09/16/2020

This program will utilize arrays to determine the strength of 5 cards 
2 - 9 using poker logic.The user is expected to enter in 5 cards 2 - 9 and
the program will provide an output of the strongest possibility of that hand.
The card logic is provided within the 6 functions where counter controlled
for loops are used to determine whether the hand of cards is either a straight,
full house, etc. */


#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;

bool  containsPair(const int hand[]);
bool  containsTwoPair(const int hand[]);
bool  containsThreeOfaKind(const int hand[]);
bool  containsStraight(const int hand[]);
bool  containsFullHouse(const int hand[]);
bool  containsFourOfaKind(const int hand[]);


int main()
{
	int count;
	int hand[ARRAY_SIZE];
	cout << "Enter 5 numeric cards, no face cards. Use 2-9." << endl;

	for (count = 0; count < ARRAY_SIZE; count++)
	{
		cout << "Card " << count + 1 << ": ";
		cin >> hand[count];
	}

	if (containsFourOfaKind(hand))
	{
		cout << "Four of a Kind!" << endl;
	}
	else if (containsFullHouse(hand))
	{
		cout << "Full House!" << endl;
	}
	else if (containsStraight(hand))
	{
		cout << "Straight!" << endl;
	}
	else if (containsThreeOfaKind(hand))
	{
		cout << "Three of a Kind!" << endl;
	}
	else if (containsTwoPair(hand))
	{
		cout << "Two Pairs!" << endl;
	}
	else if (containsPair(hand))
	{
		cout << "Pair!" << endl;
	}
	else
	{
		cout << "High Card!" << endl;
	}

}






/*This function will determine whether or not
the hand contains a four of a kind.Through a nested loop,
it will determine how many times the cards "match"
there are and the counter will increment. Since
there needs to be 6 matches for a 4 of a kind, if there
are four matches the function will return as true.*/
bool  containsFourOfaKind(const int hand[])
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = i + 1; j < ARRAY_SIZE + 1; j++)
		{
			if (hand[i] == hand[j])
			{
				counter++;
			}
		}
	}
	return counter == 6;
}






/*This function will determine whether or not
the hand contains a full house.Through a nested loop,
it will determine how many times the cards "match"
there are and the counter will increment. Since 
a full house is a pair + three of a kind, if there
are four matches the function will return as true.*/
bool  containsFullHouse(const int hand[])
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = i + 1; j < ARRAY_SIZE + 1; j++)
		{
			if (hand[i] == hand[j])
			{
				counter++;
			}
		}
	}
	return counter == 4;
}






/*This function will determine whether or not 
the hand returns a straight. It goes through
all the numbers in the hand starting with the smallest
and checks if there are numbers in the hand that are
+1, +2, +3, +4. If not, it will check the next number.
If there is a number that returns +1, +2, +3, +4 it will 
return as true and we have a straight.*/
bool  containsStraight(const int hand[])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		bool found = true;
		for (int counter = 1; counter < 5; ++counter)
		{
			bool exists = false;
			for (int j = 0; j < ARRAY_SIZE; j++)
			{
				if (hand[j] == hand[i] + counter)
				{
					exists = true;
				}
			}
			if (!exists)
			{
				found = false;
			}
		}
		if (found)
		{
			return true;
		}
	}
	return false;
}





/*This function will determine whether or not
the hand contains a three of a kind.Through a nested loop,
it will determine how many times the cards "match"
there are and the counter will increment. If there
are three matches the function will return as true.*/
bool  containsThreeOfaKind(const int hand[])
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = i + 1; j < ARRAY_SIZE + 1; j++)
		{
			if (hand[i] == hand[j])
			{
				counter++;
			}
		}
	}
	return counter == 3;
}






/*This function will determine whether or not
the hand contains two pairs.Through a nested loop,
it will determine how many times the cards "match" 
there are and the counter will increment. If there 
are two matches the function will return as true.*/
bool  containsTwoPair(const int hand[])
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = i + 1; j < ARRAY_SIZE + 1; j++)
		{
			if (hand[i] == hand[j])
			{
				counter++;
			}
		}
	}
	return counter == 2;
}





/*This function will determine whether or not
the hand contains one pair. Through a nested loop,
it will check if the hand returns a pairing.*/
bool  containsPair(const int hand[])
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = i + 1; j < ARRAY_SIZE + 1; j++)
		{
			if (hand[i] == hand[j])
			{
				return true;
			}
		}
	}
	return false;
}

/*
Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 5
Card 2: 3
Card 3: 2
Card 4: 6
Card 5: 8
High Card!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 2
Card 2: 3
Card 3: 2
Card 4: 4
Card 5: 6
Pair!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 3
Card 2: 9
Card 3: 5
Card 4: 5
Card 5: 9
Two Pairs!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 5
Card 2: 6
Card 3: 3
Card 4: 5
Card 5: 5
Three of a Kind!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 6
Card 2: 3
Card 3: 4
Card 4: 5
Card 5: 2
Straight!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 9
Card 2: 9
Card 3: 5
Card 4: 5
Card 5: 5
Full House!

Enter 5 numeric cards, no face cards. Use 2-9.
Card 1: 3
Card 2: 3
Card 3: 5
Card 4: 3
Card 5: 3
Four of a Kind!
*/
