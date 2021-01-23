//
// Created by PinkySmile on 17/01/2021.
//

#include <iostream>
#include <Client.hpp>
#include <Tournament.hpp>

int main(int argc, char **argv)
{
	if (argc == 1)
		return EXIT_FAILURE;

	ChallongeAPI::Client client{USERNAME, PASSWD};
	ChallongeAPI::Tournament &tournament = client.getTournamentByName(argv[1]);

	for (auto &p : tournament.getParticipants())
		std::cout << p->getName() << std::endl;
}