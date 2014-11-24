#include <iostream>

#include "../include/team.h"
#include "../include/characters.h"
#include "../include/items.h"

int main() {

    const std::string tA[] = {"Generic-A", "Knight-A", "Wizard-A", "Thief-A"};
    const std::string tB[] = {"Generic-B", "Knight-B", "Wizard-B", "Thief-B"};

    // Team A
    Team teamA("Team A", Color::yellow);
    Character *a1=NULL, *a2=NULL, *a3=NULL, *a4=NULL;
    teamA.addChar(a1 = new Character(tA[0]));
    teamA.addChar(a2 = new Knight(tA[1], 10));
    teamA.addChar(a3 = new Wizard(tA[2], 5));
    teamA.addChar(a4 = new Thief(tA[3], 7));
    a1->addXP(1);
    a1->setStats(25, 25, 18, 32);
    a2->addXP(3);
    a2->setStats(37, 15, 30, 18);
    a3->addXP(4);
    a3->setStats(30, 18, 28, 24);
    a4->addXP(2);
    a4->setStats(20, 30, 22, 28);

    // Team B
    Team teamB("Team B", Color::blue);
    Character *b1=NULL, *b2=NULL, *b3=NULL, *b4=NULL;
    teamB.addChar(b1 = new Character(tB[0]));
    teamB.addChar(b2 = new Knight(tB[1], 7));
    teamB.addChar(b3 = new Wizard(tB[2], 10));
    teamB.addChar(b4 = new Thief(tB[3], 3));
    b1->addXP(1);
    b1->setStats(30, 15, 32, 23);
    b2->addXP(4);
    b2->setStats(17, 30, 21, 32);
    b3->addXP(2);
    b3->setStats(20, 31, 21, 28);
    b4->addXP(3);
    b4->setStats(30, 22, 27, 21);

    // Team A items
    a1->storeItem(new Weapon("Weapon-A 1-1", 60, 9, 10), true);
    a1->storeItem(new Weapon("Weapon-A 1-2", 60, 9, 10), true);
    a1->storeItem(new HealthPotion("HP Potion", 2, 10));
    a1->storeItem(new ManaPotion("MP Potion", 2, 10));

    a2->storeItem(new Armor("Armor-A 2", 100, 1, 5), true);
    a2->storeItem(new Weapon("Weapon-A 2-1", 60, 9, 10), true);
    a2->storeItem(new Weapon("Weapon-A 2-2", 60, 9, 10), true);
    a2->storeItem(new HealthPotion("HP Potion", 2, 10));
    a2->storeItem(new ManaPotion("MP Potion", 2, 10));

    a3->storeItem(new Armor("Armor-A 3", 80, 1, 4), true);
    a3->storeItem(new Weapon("Weapon-A 3", 60, 9, 10), true);
    a3->storeItem(new HealthPotion("HP Potion", 2, 10));

    a4->storeItem(new Armor("Armor-A 4", 120, 1, 6), true);
    a4->storeItem(new Weapon("Weapon-A 4-1", 60, 9, 10), true);
    a4->storeItem(new Weapon("Weapon-A 4-2", 60, 9, 10), true);

    // Team B items
    b1->storeItem(new Weapon("Weapon-B 1", 60, 9, 10), true);
    b1->storeItem(new HealthPotion("HP Potion", 2, 10));
    b1->storeItem(new ManaPotion("MP Potion", 2, 10));

    b2->storeItem(new Armor("Armor-B 2", 100, 4, 5), true);
    b2->storeItem(new Weapon("Weapon-B 2", 60, 9, 10), true);
    b2->storeItem(new HealthPotion("HP Potion", 2, 10));
    b2->storeItem(new ManaPotion("MP Potion", 2, 10));

    b3->storeItem(new Armor("Armor-B 3", 80, 6, 4), true);
    b3->storeItem(new Weapon("Weapon-B 3", 60, 9, 10), true);
    b3->storeItem(new HealthPotion("HP Potion", 2, 10));

    b4->storeItem(new Armor("Armor-B 4", 120, 9, 6), true);
    b4->storeItem(new Weapon("Weapon-B 4-1", 60, 2, 10), true);
    b4->storeItem(new Weapon("Weapon-B 4-2", 60, 4, 10), true);

    // Team print info
    std::cout << "********* " << teamA.toString() << " *********\n";
    std::cout << teamA.getCharsInfo() << "\n";
    std::cout << "********* " << teamB.toString() << " *********\n";
    std::cout << teamB.getCharsInfo() << "\n";

    // Attacks!
    std::cout << "********* BATTLE *********\n";
    const int rounds = 4;
    const int attacksPerTeamPerRound = 2; // should not have more attacks than players (max 1 attack per player or will cause an infinite loop)
    for(int t=0; t<rounds; t++) {
        std::cout << "** ROUND " << t+1 << " **\n";

        // Generate attack list (2 * attacksPerTeamPerRound because we have 2 teams, so 1 attack )
        std::vector<int> playerA_AB, playerB_AB, playerA_BA, playerB_BA;
        for(int a=0; a<2*attacksPerTeamPerRound; a++) {
            int player;
            bool contains;

            // Attack A->B, rand player A
            srand(clock());
            contains = true;
            while(contains) {
                contains = false;
                player = rand()%teamA.size();
                for(std::vector<int>::iterator it = playerA_AB.begin(); it!=playerA_AB.end(); it++) {
                    if(*it==player) { // already on list
                        contains = true;
                        break;
                    }
                }
            }
            playerA_AB.push_back(player);

            // Attack A->B, rand player B
            srand(clock());
            contains = true;
            while(contains) {
                contains = false;
                player = rand()%teamB.size();
                for(std::vector<int>::iterator it = playerB_AB.begin(); it!=playerB_AB.end(); it++) {
                    if(*it==player) { // already on list
                        contains = true;
                        break;
                    }
                }
            }
            playerB_AB.push_back(player);

            // Attack B->A, rand player A
            srand(clock());
            contains = true;
            while(contains) {
                contains = false;
                player = rand()%teamA.size();
                for(std::vector<int>::iterator it = playerA_BA.begin(); it!=playerA_BA.end(); it++) {
                    if(*it==player) { // already on list
                        contains = true;
                        break;
                    }
                }
            }
            playerA_BA.push_back(player);

            // Attack B->A, rand player B
            srand(clock());
            contains = true;
            while(contains) {
                contains = false;
                player = rand()%teamB.size();
                for(std::vector<int>::iterator it = playerB_BA.begin(); it!=playerB_BA.end(); it++) {
                    if(*it==player) { // already on list
                        contains = true;
                        break;
                    }
                }
            }
            playerB_BA.push_back(player);

        }

        // Play round
        // Each player attacked may use HealthPotion if available
        for(int a=0; a<attacksPerTeamPerRound; a++) {
            int indexA, indexB;
            std::string nameA, nameB;
            Character *playerA, *playerB;

            // Attack A->B
            indexA = playerA_AB.at(0);
            indexB = playerB_AB.at(0);
            nameA = tA[indexA];
            nameB = tB[indexB];
            playerA = teamA.searchChar(nameA);
            playerB = teamB.searchChar(nameB);

            playerA->attack(playerB); // ATTACK!
            if(playerB->getHP()<100 && playerB->hasItem("HP Potion")) // use HP if available and necessary
                playerB->useItem("HP Potion");

            playerA_AB.erase(playerA_AB.begin());
            playerB_AB.erase(playerB_AB.begin());

            // Attack B->A
            indexA = playerA_BA.at(0);
            indexB = playerB_BA.at(0);
            nameA = tA[indexA];
            nameB = tB[indexB];
            playerA = teamA.searchChar(nameA);
            playerB = teamB.searchChar(nameB);

            playerB->attack(playerA); // ATTACK!
            if(playerA->getHP()<100 && playerA->hasItem("HP Potion")) // use HP if available and necessary
                playerA->useItem("HP Potion");

            playerA_BA.erase(playerA_BA.begin());
            playerB_BA.erase(playerB_BA.begin());
        }

        // Round result
        float rA = teamA.resolveBattle(teamB);
        teamB.resolveBattle(teamA);
        if(rA>0)
            std::cout << ">>> Team A wins!\n";
        else if(rA<0)
            std::cout << ">>> Team B wins!\n";
        else
            std::cout << ">>> Draw!\n";

        std::cout << "\n";
    }

    // Print game results
    std::cout << teamA.getResults();
    std::cout << teamB.getResults();
    std::cout << std::endl;

	return 0;
}
