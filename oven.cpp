// Addeline Mitchell
// Mar 7, 2017
// oven.cpp
//
// This is an interactive simulated demonstration of
// semi-strict OoOE for CS441 presentation purposes.


#include "ings.h"

static deque<Ing> unused, bowl1, bowl2;
static string dry = "";
bool badMix = false, badCombo = false, badBake = false;

static void menu();



// HOUSEKEEPING FUNC(S) //

static void init() // gather ingredients in the kitchen
{
	Ing ing0(0, 14.0, "Cookies", "Thin Mints", true);
	Ing ing1(1, 3.0, "", "Egg Whites", false);
	Ing ing2(2, 0.0625, "tsp", "Salt", true);
	Ing ing3(3, 0.75, "cup", "Sugar", true);
	Ing ing4(4, 0.5, "tsp", "Vanilla", false);
	Ing ing5(5, 0.5, "cup", "Chopped Walnuts", true);

	unused.push_back(ing0);
	unused.push_back(ing1);
	unused.push_back(ing2);
	unused.push_back(ing3);
	unused.push_back(ing4);
	unused.push_back(ing5);
}

static void pad()
{
	for (int i = 0; i < 50; ++i)
	{ cout << "\n\n" << endl; }
}



// MENU OPT 1 FUNC(S) //

static void instructions()
{
	cout << "\n\nINSTRUCTIONS:\nAdd all dry ingredients together in a bowl.\n"
		<< "Add all wet ingredients together in the other bowl.\n"
		<< "(It does not matter whether you add the wet or dry ings together first,\n"
		<< "just as long as they are initially combined separately.)\n"
		<< "Combine bowls, then bake and find out what monstrosity you've created.\n"
		<< "\nWARNING: You can check which ings you haven't used and which ings are\n"
		<< "in each bowl, but you cannot remove an ingredient once you have added it.\n\n"
		<< endl;

	menu();
}



// MENU OPT 2, 3, 4 FUNC(S) //

static void checkDry(Ing in)
{
	if (in.getIsDry()) { dry = "dry"; }
	else { dry = "wet"; }
}

static void printStats(Ing in)
{
	checkDry(in);

	cout << "Ingredient: " << in.getName() << endl
		<< "Amount: " << in.getAmt() << " " << in.getUnit() << endl
		<< "State: " << dry << endl << endl;
}

static void check(deque<Ing> in)
{
	pad();

	if (in.empty())
	{ cout << "\nNO INGREDIENTS PRESENT\n" << endl; }
	else
	{
		cout << "\nINGREDIENTS PRESENT\n" << endl;
		for (int i = 0; i < in.size(); ++i)
		{ printStats(in[i]); }
	}
}



// MENU OPT 5, 6 FUNC(S) //

static void printOpt(Ing in)
{
	cout << "ID: " << in.getID()
		<< " --- Ingredient: " << in.getName() << endl << endl;
}

static int seek(int in)
{
	for (int i = 0; i < unused.size(); ++i)
	{ if (in == unused[i].getID()) { return i; } }

	return 8;
}

static void ingSelect(int in, bool opt5)
{
	pad();
	
	int sel;

	sel = seek(in);
	if (8 == sel)
	{ cout << "THAT ING ISN'T THERE, TRY AGAIN\n" << endl; }
	else
	{
		if (opt5)
		{
			bowl1.push_back(unused[sel]);
			unused.erase(unused.begin() + sel);
		}
		else
		{
			bowl2.push_back(unused[sel]);
			unused.erase(unused.begin() + sel);
		}
	}

	menu();
}

static void choose(bool opt5)
{
	int opt;

	pad();
	
	if (!unused.empty())
	{
		while (true)
		{
			for (int i = 0; i < unused.size(); ++i)
			{ printOpt(unused[i]); }
			cout << "\nSELECT ID: ";

			if (!(cin >> opt) || (opt < 0) || (opt > 5)) // input sanitization
			{
				cout << "\nTRY AGAIN\n\n" << endl;
				cin.clear();
				cin.ignore();
			}
			else { break; }
		}
		ingSelect(opt, opt5);
	}
	else
	{ cout << "NO MORE UNUSED INGS\n\n" << endl; }

	menu();
}



// MENU OPT 8 FUNC(S) //

static void checkMix()
{
	if ((false != bowl1[0].getIsDry() && false != bowl1[1].getIsDry())
		|| (false != bowl1[bowl1.size() - 2].getIsDry()
			&& false != bowl1[bowl1.size() - 1].getIsDry())) {}
	else
	{ badMix = true; }
}

static void bake()
{
	if (!bowl1.empty())
	{ checkMix(); }

	pad();
	
	if (!badBake && !badCombo && !badMix)
	{
		cout << "The pie comes out of the oven looking fa-bu-lous~.\n"
			<< "After it cools, you cut a slice, place it on a plate\n"
			<< "wrap it in clear plastic wrap, and put it in the fridge\n"
			<< "for your SO. You are a good person. You feel good about\n"
			<< "having made this pie, which is why you gorge yourself on\n"
			<< "the contents of the mostly full pie tin." << endl;
	}
	else if (badBake)
	{
		cout << "No more than five minutes after you put the pie in the\n"
			<< "oven, it explodes. Your curtains, carpet, cieling, and\n"
			<< "various kitchen appliances catch on fire. The smoke alarm\n"
			<< "screams your failures at you incessantly. Your house burns\n"
			<< "down. You don't deserve pie." << endl;
	}
	else
	{
		if (badCombo && badMix)
		{
			cout << "The pie comes out of the oven looking lumpy. After it\n"
				<< "cools, you attempt to cut a slice for yourself. The pie\n"
				<< "falls apart, crumbling more with every touch. In your\n"
				<< "desperation, you tip the pie tin and try to scrape out\n"
				<< "an amount equivalent to a slice onto a plate. You feel\n"
				<< "that you deserve some pie after all that hard work. You've\n"
				<< "taken a couple of bites and suddenly, you don't feel so\n"
				<< "good. Bile rises in your throat and you vomit on your\n"
				<< "pristine white carpet. Your carpet-cleaning bill is going\n"
				<< "to be through the roof." << endl;
		}
		else if (badCombo && !badMix)
		{
			cout << "The pie comes out of the oven looking lumpy. After it\n"
				<< "cools, you attempt to cut a slice for yourself. The pie\n"
				<< "falls apart, crumbling more with every touch. In your\n"
				<< "desperation, you tip the pie tin and try to scrape out\n"
				<< "an amount equivalent to a slice onto a plate. Your\n"
				<< "pathetic excuse for a pie falls out of the tin. No chunk\n"
				<< "of pie is larger than a standard-size marble, good luck\n"
				<< "cleaning up all those crumbs." << endl;
		}
		else // !badcombo && badMix
		{
			cout << "The pie comes out of the oven looking alright.\n"
				<< "After it cools, you cut a slice for yourself and dig in.\n"
				<< "You feel that you deserve some pie after all that hard\n"
				<< "work. You've taken a couple of bites and suddenly, you\n"
				<< "don't feel so good. Bile rises in your throat and you\n"
				<< "vomit on your pristine white carpet. Your carpet-cleaning\n"
				<< "bill is going to be through the roof." << endl;
		}
	}

	cout << "\n\nPress ENTER to Quit";
	cin.get();
	while (cin.get() != '\n');

	exit(0);
}



// MAIN MENU FUNCS //

static void menuSelect(int in)
{
	int j;

	pad();

	switch (in)
	{
		case 1:
			instructions();
			cout << endl << endl;
			break;
		
		case 2:
			check(unused);
			cout << endl << endl;
			break;
		
		case 3:
			check(bowl1);
			cout << endl << endl;
			break;
		
		case 4:
			check(bowl2);
			cout << endl << endl;
			break;
		
		case 5:
			choose(true);
			cout << endl << endl;
			break;
		
		case 6:
			choose(false);
			cout << endl << endl;
			break;
		
		case 7:
			if(!bowl2.empty())
			{
				j = bowl2.size();
				for (int i = 0; i < j; ++i)
				{
					bowl1.push_back(bowl2[0]);
					bowl2.pop_front();
				}
				if ((2 != bowl2.size() && 6 == bowl1.size() + bowl2.size())
					|| (4 != bowl2.size() && 6 == bowl1.size() + bowl2.size()))
				{ badCombo = true; }
			}
			cout << "INGS HAVE BEEN COMBINED INTO BOWL 1\n" << endl;
			break;
		
		case 8:
			if (6 != bowl1.size())
			{ badBake = true; }
			bake();
			cout << endl << endl;
			break;
		
		case 9:
			exit(0);
		
		default:
			cout << "NOT AN OPTION, TRY AGAIN\n" << endl;
			break;
	}

	menu();
}

static void menu()
{
	int opt;

	while (true)
	{
		cout << "MENU:\n\n1 :: READ INSTRUCTIONS\n"
			<< "2 :: CHECK UNUSED INGS\n"
			<< "3 :: CHECK BOWL 1\n"
			<< "4 :: CHECK BOWL 2\n"
			<< "5 :: ADD ING TO BOWL 1\n"
			<< "6 :: ADD ING TO BOWL 2\n"
			<< "7 :: COMBINE BOWLS\n"
			<< "8 :: BAKE\n"
			<< "9 :: QUIT\n\n"
			<< "SELECTION: ";

		if(!(cin >> opt) || (opt < 1) || (opt > 9)) // input sanitization
		{
			cout << "\nTRY AGAIN\n\n" << endl;
			cin.clear();
			cin.ignore();
		}
		else { break; }
	}

	menuSelect(opt);
}

int main()
{
	init();
	menu();
}
