#include <iostream>
#include <fstream>
#include "Soldier/Soldier.h"
#include "Commander/Commander.h"
#include "General/General.h"

void writeGeneralToFile(const General & general){
    std::ofstream out("general.txt");
    if(!out.is_open()){
        std::cout<<"Problem with file";
        return;
    }

    out<<"General name: "<<general.getName()<<'\n';
    out<<"Army description: "<<general.getDescription()<<'\n';
    float finances = general.getSalary() + general.getAllSalaries();
    out<<"Needed financial resources: "<<finances<<'\n';
    int skills = general.getSkillsCount() + general.getAllSkillsCount();
    out<<"All skills: "<<skills<<'\n';
    float skillsAvg = general.getAllSkilsAvg();
    out<<"All skills avg: "<<skillsAvg<<'\n';

    out.close();
}

int main() {
    Soldier s1("Ivan", 19, 2, 1000);
    Soldier s2("Stoyan", 19, 3, 1300);
    Soldier s3("Dani", 23, 6, 1500);
    Soldier s4("Vasil", 24, 1, 900);

    Commander c1("Kristian", 26, 12, 2300);
    c1.setDescription("This is Kristian's Army. I really enjoy working with these awesome people.");
    std::cout << c1.getName() << std::endl;
    c1.addSoldier(s1);
    c1.addSoldier(s2);
    c1.getSoldiers();
    std::cout << c1.getDescription() << std::endl;

    Commander c2("Vladimir", 30, 14, 2600);
    c2.setDescription("This is Vladimir's Army. I really enjoy working with these awesome people.");
    std::cout << c2.getName() << std::endl;
    c2.addSoldier(s3);
    c2.addSoldier(s4);
    c2.getSoldiers();
    std::cout << c2.getDescription() << std::endl;

    General g1("Rambo",67,23,5000);
    g1.setDescription("I am the general and the army is very strong");
    std::cout << g1.getName() << std::endl;
    g1.addCommander(c1);
    g1.addCommander(c2);
    g1.getCommanders();
    std::cout << g1.getDescription() << std::endl;

    writeGeneralToFile(g1);

}
