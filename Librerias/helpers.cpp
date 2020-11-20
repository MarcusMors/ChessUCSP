#include <iostream>
#include "helpers.h"

void cleanScreen(int I = 30)
{
	for (int i = 0; i < I; i++)
		std::cout << std::endl;
}

int letterToInt(char letter)
{
	int num;
	return num;
}

int sumUp(int arr[], int length)
{
	int accumulator = 0;
	for (int i = 0; i < length; i++)
		accumulator += arr[i];

	return accumulator;
}

long long max(long long arr[], long long length)
{
	long long max = -10000;
	for (long long i = 0; i < length; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

long long min(long long arr[], long long length)
{
	long long min = 10000;
	for (long long i = 0; i < length; i++)
	{
		min = (min > arr[i]) ? arr[i] : min;
	}
	return min;
}

OnceAnnouncement::OnceAnnouncement(int I = 0)
{
	{
		cleanScreen();
		switch (I)
		{
		case 0:
			cout << " ██████╗██╗  ██╗███████╗███████╗███████╗" << endl;
			cout << "██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << endl;
			cout << "██║     ███████║█████╗  ███████╗███████╗" << endl;
			cout << "██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << endl;
			cout << "╚██████╗██║  ██║███████╗███████║███████║" << endl;
			cout << " ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << endl;
			cleanScreen(3);
			break;
		case 1:
			cout << " ▄████▄   ██░ ██ ▓█████   ██████   ██████ " << endl;
			cout << "▒██▀ ▀█  ▓██░ ██▒▓█   ▀ ▒██    ▒ ▒██    ▒ " << endl;
			cout << "▒▓█    ▄ ▒██▀▀██░▒███   ░ ▓██▄   ░ ▓██▄   " << endl;
			cout << "▒▓▓▄ ▄██▒░▓█ ░██ ▒▓█  ▄   ▒   ██▒  ▒   ██▒" << endl;
			cout << "▒ ▓███▀ ░░▓█▒░██▓░▒████▒▒██████▒▒▒██████▒▒" << endl;
			cout << "░ ░▒ ▒  ░ ▒ ░░▒░▒░░ ▒░ ░▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░" << endl;
			cout << "  ░  ▒    ▒ ░▒░ ░ ░ ░  ░░ ░▒  ░ ░░ ░▒  ░ ░" << endl;
			cout << "░         ░  ░░ ░   ░   ░  ░  ░  ░  ░  ░  " << endl;
			cout << "░ ░       ░  ░  ░   ░  ░      ░        ░  " << endl;
			cout << "░                                         " << endl;
			cout << endl;
			break;
		case 2:
			cout << " ▄████████    ▄█    █▄       ▄████████    ▄████████    ▄████████ " << endl;
			cout << "███    ███   ███    ███     ███    ███   ███    ███   ███    ███ " << endl;
			cout << "███    █▀    ███    ███     ███    █▀    ███    █▀    ███    █▀  " << endl;
			cout << "███         ▄███▄▄▄▄███▄▄  ▄███▄▄▄       ███          ███        " << endl;
			cout << "███        ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ▀███████████ ▀███████████ " << endl;
			cout << "███    █▄    ███    ███     ███    █▄           ███          ███ " << endl;
			cout << "███    ███   ███    ███     ███    ███    ▄█    ███    ▄█    ███ " << endl;
			cout << "████████▀    ███    █▀      ██████████  ▄████████▀   ▄████████▀  " << endl;
			cleanScreen(5);
			break;
		case 3:
			cout << " ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ " << endl;
			cout << "▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌" << endl;
			cout << "▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ " << endl;
			cout << "▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          " << endl;
			cout << "▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ " << endl;
			cout << "▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌" << endl;
			cout << "▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌" << endl;
			cout << "▐░▌          ▐░▌       ▐░▌▐░▌                    ▐░▌          ▐░▌" << endl;
			cout << "▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄█░▌ ▄▄▄▄▄▄▄▄▄█░▌" << endl;
			cout << "▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌" << endl;
			cout << " ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ " << endl;
			cleanScreen(5);
			break;
		case 4:

			cout << "Chess" << endl;
			break;
		case 5:
			cout << "________/\\\\\\\\\\\\\\\\\\__/\\\\\\________/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\\\\\\\\\\\\\___        " << endl;
			cout << " _____/\\\\\\////////__\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\///////////____/\\\\\\/////////\\\\\\___/\\\\\\/////////\\\\\\_       " << endl;
			cout << "  ___/\\\\\\/___________\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\______________\\//\\\\\\______\\///___\\//\\\\\\______\\///__      " << endl;
			cout << "   __/\\\\\\_____________\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\_______\\////\\\\\\___________\\////\\\\\\_________     " << endl;
			cout << "    _\\/\\\\\\_____________\\/\\\\\\/////////\\\\\\_\\/\\\\\\///////___________\\////\\\\\\___________\\////\\\\\\______    " << endl;
			cout << "     _\\//\\\\\\____________\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_____________________\\////\\\\\\___________\\////\\\\\\___   " << endl;
			cout << "      __\\///\\\\\\__________\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\______________/\\\\\\______\\//\\\\\\___/\\\\\\______\\//\\\\\\__  " << endl;
			cout << "       ____\\////\\\\\\\\\\\\\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\\///\\\\\\\\\\\\\\\\\\\\\\/___\\///\\\\\\\\\\\\\\\\\\\\\\/___ " << endl;
			cout << "        _______\\/////////__\\///________\\///__\\///////////////____\\///////////_______\\///////////_____" << endl;
			cleanScreen(5);
			break;
		case 6:
			cout << "          _____                    _____                    _____                    _____                    _____          " << endl;
			cout << "         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\         " << endl;
			cout << "        /::\\    \\                /::\\____\\                /::\\    \\                /::\\    \\                /::\\    \\        " << endl;
			cout << "       /::::\\    \\              /:::/    /               /::::\\    \\              /::::\\    \\              /::::\\    \\       " << endl;
			cout << "      /::::::\\    \\            /:::/    /               /::::::\\    \\            /::::::\\    \\            /::::::\\    \\      " << endl;
			cout << "     /:::/\\:::\\    \\          /:::/    /               /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\     " << endl;
			cout << "    /:::/  \\:::\\    \\        /:::/____/               /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\    " << endl;
			cout << "   /:::/    \\:::\\    \\      /::::\\    \\              /::::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\   " << endl;
			cout << "  /:::/    / \\:::\\    \\    /::::::\\    \\   _____    /::::::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\  " << endl;
			cout << " /:::/    /   \\:::\\    \\  /:::/\\:::\\    \\ /\\    \\  /:::/\\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\ " << endl;
			cout << "/:::/____/     \\:::\\____\\/:::/  \\:::\\    /::\\____\\/:::/__\\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\" << endl;
			cout << "\\:::\\    \\      \\::/    /\\::/    \\:::\\  /:::/    /\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /" << endl;
			cout << " \\:::\\    \\      \\/____/  \\/____/ \\:::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/ " << endl;
			cout << "  \\:::\\    \\                       \\::::::/    /    \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\     " << endl;
			cout << "   \\:::\\    \\                       \\::::/    /      \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\    " << endl;
			cout << "    \\:::\\    \\                      /:::/    /        \\:::\\   \\::/    /        \\:::\\  /:::/    /        \\:::\\  /:::/    /    " << endl;
			cout << "     \\:::\\    \\                    /:::/    /          \\:::\\   \\/____/          \\:::\\/:::/    /          \\:::\\/:::/    /     " << endl;
			cout << "      \\:::\\    \\                  /:::/    /            \\:::\\    \\               \\::::::/    /            \\::::::/    /      " << endl;
			cout << "       \\:::\\____\\                /:::/    /              \\:::\\____\\               \\::::/    /              \\::::/    /       " << endl;
			cout << "        \\::/    /                \\::/    /                \\::/    /                \\::/    /                \\::/    /        " << endl;
			cout << "         \\/____/                  \\/____/                  \\/____/                  \\/____/                  \\/____/         " << endl;
			cleanScreen(8);
			break;

		default:
			break;
		}
		cleanScreen(15);
		cout << "\t\tInput [anything] to continue:" << endl;
		cout << "\t\t\t\t";
		cin >> anything;
	}
}
OnceAnnouncement::~OnceAnnouncement()
{
	cout << "Credits\n";
	// creditos
}

//! ASK LOAIZA-SENSEI
// OnceAnnouncement::OnceAnnouncement(int I = 0)
// {
// }
