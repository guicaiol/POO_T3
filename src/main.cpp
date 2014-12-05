/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include <iostream>
#include <ctime>
#include "game/game.h"
#include "character/characters.h"
#include "item/items.h"

std::string generateRandomAlias() {
    const int size = 16;
    const std::string characterName[] = {
        "Thor", "Capitao America", "Hulk", "Homem de Ferro", "Homem Aranha",
        "Flash", "Viuva Negra", "Mulher Maravilha", "Mulher Gato", "Gaviao Arqueiro",
        "Lanterna Verde", "Wolverine", "Ciclope", "Vampira", "Colosso", "Magneto", "Charles Xavier"
    };
    static int lastUsed = -1;

    lastUsed++;
    if(lastUsed>=size)
        lastUsed = 0;
    return characterName[lastUsed];
}

std::string generateRandomItemName() {
    const int size = 16;
    const std::string itemName[] = {
        "Furia", "Dragao", "Extremo", "Antigo", "Caos",
        "Salamandra", "Arco-iris", "Furacao", "Tornado", "Tufao",
        "Chamas", "Fogo", "Ventania", "Tempestade", "Lendario", "Titan"
    };
    static int lastUsed = -1;

    lastUsed++;
    if(lastUsed>=size)
        lastUsed = 0;
    return itemName[lastUsed];
}

int main() {
    Game *lastGame=NULL;
    Game *game=NULL;

    while(true) {
        system("clear");

        int command = 0;
        std::cout << "---- Simulador de jogos de batalha ----\n";
        if(lastGame==NULL)
            std::cout << "Comandos disponiveis:\n[0] Sair\n[1] Simulador jogo\n";
        else
            std::cout << "Comandos disponiveis:\n[0] Sair\n[1] Simulador jogo\n[2] Simular com mesmos times\n";
        std::cout << "Comando: ";
        std::cin >> command;

        // Exit command
        if(command==0)
            break;

        // Repeat game
        if(command==1) {
            std::cout << "\n---- Configuracao de batalha ----\n";

            // Ask for game parameters
            int rounds = 0;
            do {
                std::cout << "Quantos rounds? ";
                std::cin >> rounds;
                if(rounds<1)
                    std::cout << ">> Mínimo de 1 round.\n";
            } while(rounds<1);

            int roundTime = 0;
            do {
                std::cout << "Quanto tempo cada round (segundos, minimo 5)? ";
                std::cin >> roundTime;
                if(roundTime<5)
                    std::cout << ">> Mínimo de 5 segundos por rounds.\n";
            } while(roundTime<5);


            // Create game
            game = new Game(rounds, roundTime);
            if(lastGame!=NULL)
                delete lastGame;
            lastGame = game;

            // Ask teams
            int numTeams = 0;
            do {
                std::cout << "Quantos times nesse jogo? ";
                std::cin >> numTeams;
                if(numTeams<2)
                    std::cout << ">> Mínimo de 2 times por jogo.\n";
                if(numTeams>4)
                    std::cout << ">> Máximo de 4 times por jogo.\n";
            } while(numTeams<2 || numTeams>4);

            // Ask teams info
            int teamColor = 0;
            for(int i=1; i<=numTeams; i++) {
                std::cout << "\n-- Time #" << i << " --\n";

                // Team name
                std::string teamName;
                std::cout << "Nome do time? ";
                std::cin >> teamName;

                // Create team
                Team *team = new Team(teamName, (Color)teamColor);
                teamColor++;
                std::cout << "Cor do time: " << HColor::colorToString((Color)teamColor) << "\n";
                if(teamColor>=5)
                    teamColor = 0;

                // Team players level
                int playersAverageLevel = 0;
                do {
                    std::cout << "Nível médio dos jogadores desse time? ";
                    std::cin >> playersAverageLevel;
                    if(playersAverageLevel<1)
                        std::cout << ">> Level medio deve ser no minimo 1.\n";
                    if(playersAverageLevel>100)
                        std::cout << ">> Level medio deve ser no maximo 100.\n";
                } while(playersAverageLevel<1 || playersAverageLevel>100);

                // Create characters, selecting class and attributes randomly
                int charClass = 0;
                for(int i=0; i<3; i++) {
                    // Random name
                    std::string chName = generateRandomAlias();

                    // Random special attribute
                    srand(clock());
                    int specialAttr = (rand()%25)+1;

                    // Create character
                    Character *ch = NULL;
                    switch(charClass++) {
                        default:
                        case 0:
                            ch = new Knight(chName, specialAttr);
                            break;
                        case 1:
                            ch = new Thief(chName, specialAttr);
                            break;
                        case 2:
                            ch = new Wizard(chName, specialAttr);
                            break;
                    }

                    // Generate random base attr
                    srand(clock());
                    int speed = (rand()%6)+1;
                    int attr[3] = {0};
                    for(int i=0; i<3; i++)
                        attr[i] = (rand()%25)+1;
                    ch->setStats(attr[0], speed, attr[1], attr[2]);

                    // Generate level, based on average level (+-3 from average)
                    srand(clock());
                    int level = playersAverageLevel+(rand()%5)-2;
                    if(level<1)
                        level = 1;
                    if(level>100)
                        level = 100;
                    ch->addXP(level);

                    // Generate items
                    srand(clock());
                    int numWeapons = (rand()%2)+1;
                    for(int i=0; i<numWeapons; i++) {
                        std::string weaponName = generateRandomItemName();
                        int atkPts = (rand()%9)+1;
                        int range = (rand()%5)+1;
                        int atkSpeed = (rand()%15)+1;

                        Item *item = new Weapon(weaponName, 25, atkPts, range, atkSpeed);
                        ch->storeItem(item);
                        ch->equipItem(item->getName());
                    }

                    // Generate armor
                    srand(clock());
                    std::string armorName = generateRandomItemName();
                    int defPts = (rand()%20)+1;
                    int weight = (rand()%20)+1;

                    ch->storeItem(new Armor(armorName, 25, defPts, weight));

                    // Generate potion
                    srand(clock());
                    int numHP = (rand()%3)+1;
                    for(int i=0; i<numHP; i++)
                        ch->storeItem(new HealthPotion(10, 15));

                    // Add character to team
                    team->addChar(ch);
                    std::cout << ">> " << ch->getName() << " (" << ch->getCharacterClass() << ") adicionado ao time, XP: " << ch->getXP() << ".\n";
                }

                // Add team to game
                game->addTeam(team);
            }
        } else {
            game = lastGame;
        }

        game->start();
        game->wait();
    }

    if(lastGame!=NULL)
        delete lastGame;

    return 0;
}
