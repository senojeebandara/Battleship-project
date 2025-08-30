#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Function Declaration

int random(int min, int max);

//void eship_details(char type, string gunType, float impactPower, int minAngle, int maxAngle, int Vmin, int Vmax );
float minrangeof_escort(int Vmin, float g);
float maxrangeof_escort(int Vmax, int min_ang_e, float g);
void saveBattlefieldConditions(int Escortships, int x_battle, int y_battle, int canva_1, int canva_2);
void saveEshipConditions(int E_index, float time, int eship_dim);
void simulationResults(int x_battle, int y_battle, int hitEscortships);
int random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}


//Constant declaration
const float PI = 3.14159;
const float g=9.81;// Acceleration due to gravity(m/s^2)


 //creating structures for the battleship and escortship
    typedef struct escortships {
        char typenotation[2];
        char Typename[30];
        int coordinates[2];
        char gunName[30];
        float impactPower;
        int maxVelocity;
        int minVelocity;
        int maxAngle;
        int minAngle;
    } escortships;

    typedef struct battleship {
        char type_notation[2];
        char type_name[10];
        int coordinates;
        char gun_name[30];
        float impact_power;
        int max_velocity;
        int min_velocity;
        int max_angle;
        int angle_range;
    } battleship;

//main function
int main() {
    int canva_1, canva_2;
    printf("Enter the length and width of the canvas: \n");
    scanf("%d", &canva_1);
    scanf("%d", &canva_2);
    int canva_size = canva_1 * canva_2;
    printf("The area of the canvas: %d m^2\n", canva_size);



    int  Vb; //Maximum Velocity of the Battleship shell
    char battleship_type[2];
    FILE *Battleship;
    Battleship = fopen("battleship.txt", "w"); //storing the battleship details in a text file

    if (Battleship == NULL) {
        printf("Unable to open the text file\n");
        return 1;
    }

    //Battleship types
    printf("\n");
    printf("\nTypes of Battleships\n");
    printf("USS Iowa (BB-61) - U\n");
    printf("MS King George V - M\n");
    printf("Richeliev - R\n");
    printf("Sovetsky Soyuz-class - S\n");
    printf("Enter the battleship type: ");
    scanf("%s", battleship_type);

    Vb=random(10,100); // Maximum Velocity of the battleship shell

    switch (battleship_type[0]) {
        case 'U':
            printf("Type Name: USS Iowa (BB - 61)\n");
            printf("Gun Name: 50-caliber Mark 7 gun\n");
            printf("position - %d , %d\n", canva_1, canva_2);
            printf("Velocity - %d,\n", Vb);
            fprintf(Battleship, "Type Name: USS Iowa (BB - 61)\n","Gun Name: 50-caliber Mark 7 gun\n");
            break;
        case 'M':
            printf("Type Name: MS King George V\n");
            printf("Gun Name: (356 mm) Mark VII gun\n");
            printf("position - %d , %d\n", canva_1, canva_2);
            printf("Velocity - %d,\n", Vb);
            fprintf(Battleship, "Type Name: MS King George V\n", "Gun Name: (356 mm) Mark VII gun\n");
            break;
        case 'R':
            printf("Type Name: Richeliev\n");
            printf("Gun Name:(15 inch) Mle 1935 gun\n");
            printf("position - %d , %d\n", canva_1, canva_2);
            printf("Velocity - %d,\n", Vb);
            fprintf(Battleship, "Type Name: Richeliev\n", "Gun Name: (15 inch) Mle 1935 gun\n");
            break;
        case 'S':
            printf("Type Name: Sovetsky Soyuz-class\n");
            printf("Gun Name: (16 inch) B-37 gun\n");
            printf("position - %d , %d\n", canva_1, canva_2);
            printf("Velocity - %d,\n", Vb);
            fprintf(Battleship, "Type Name: Sovetsky Soyuz-class\n", "Gun Name: (16 inch) B-37 gun\n");
            break;
        default:
            fprintf(Battleship, "Invalid data");
            break;
    }

    // Save the escortship types in a text file
    char escort1[10];
    FILE *escort = fopen("Escortship data.txt", "w");

    if (escort == NULL){
        printf("Error opening the file.\n");
        return 1;
    }

    int Escortships;
    printf("Enter number of escortships: \n", Escortships);
    scanf("%d", &Escortships);

    //creating an array to store the escortship details
    escortships eship[Escortships];




    srand(time(NULL)); //seed the random number generator with current time
    int j=1;
    int sankBattleship =0; //Flag to indicate if the battleship is sunk

    float total_time =0.0; //store the total time taken


    while(j<=Escortships && !sankBattleship){ //loop to get the escortships

    //generating x and y coordinates of the escortships randomly
    int x = random(0, canva_1 - 1);
    int y = random(0, canva_2 - 1);

   //storing the x and y coordinates in the array
    eship[j-1].coordinates[0] = x;
    eship[j-1].coordinates[1] = y;


    //minimum and maximum angles of the escortship shell
    int min_ang_e;
    int max_ang_e;

    //minimum and maximum velocities of the escortship shell
    int Vmin;
    int Vmax;


    //choosing the escortship type
    int type = random(1, 5);
    switch (type){
        case 1:
            printf("Esortship %d: \n", j);
            printf("EscortShip Index: EA\n");
            printf("EscortShip position : (%d,%d)\n", x, y);
            printf("EscortShip Type: 1936A-class Destroyer\n");
            printf("EscortShip Gun Name:SK C/34 naval gun\n");
            printf("Impact Power: 0.08\n");
            Vmin= random(0, Vb-50);
            Vmax= 1.2 * Vb;
            min_ang_e = random(0,20);
            max_ang_e = min_ang_e + 20;

            printf("Minimum Velocity: %d\n", Vmin);
            printf("Maximum Velocity: %d\n", Vmax);
            printf("Minimum Angle: %d\n", min_ang_e);
            printf("Maximum Angle: %d\n", max_ang_e);
            fprintf(escort,"escortship %d : position: (%d,%d)\n", j, x, y);
            fprintf(escort,"                            type Name: 1936A-class Destroyer\n");
            fprintf(escort,"                            Gun Name: SK C/34 naval gun\n");
            fprintf(escort,"                            Impact Power: 0.06\n");
            fprintf(escort,"                            Minimum Velocity: %d, Maximum Velocity - %d\n", Vmin, Vmax);
            fprintf(escort,"                            Minimum Angle: %d, Maximum Angle - %d\n", min_ang_e, max_ang_e);
            printf("\n");
            break;
        case 2:
                printf("Esortship %d: \n", j);
                printf("EscortShip Index: EB\n");
                printf("EscortShip position : (%d,%d)\n",x, y);
                printf("EscortShip Type: Gabbiano-class Corvette\n");
                printf("EscortShip Gun Name: L/47 dualpurpose gun\n");
                printf("Impact Power: 0.06\n");

                Vmin= random(0, Vb-50);
                Vmax= random(Vmin,Vb);
                min_ang_e = random(0,20);
                max_ang_e = min_ang_e + 30;

                printf("Minimum Velocity: %d\n", Vmin);
                printf("Maximum Velocity: %d\n", Vmax);
                printf("Minimum Angle: %d\n", min_ang_e);
                printf("Maximum Angle: %d\n", max_ang_e);
                fprintf(escort,"escortship %d : position: (%d,%d)\n", j, x, y);
                fprintf(escort,"                            type Name: Gabbiano-class Corvette\n");
                fprintf(escort,"                            Gun Name: L/47 dualpurpose gun\n");
                fprintf(escort,"                            Impact Power: 0.06\n");
                fprintf(escort,"                            Minimum Velocity: %d, Maximum Velocity - %d\n", Vmin, Vmax);
                fprintf(escort,"                            Minimum Angle: %d, Maximum Angle - %d\n", min_ang_e, max_ang_e);
                printf("\n");
                break;
            case 3:
                    printf("Esortship %d: \n", j);
                    printf("EscortShip Index: EC\n");
                    printf("EscortShip position : (%d,%d)\n",x, y);
                    printf("EscortShip Type: Matsu-class Destroyer\n");
                    printf("EscortShip Gun Name: Type 89 dualpurpose gun\n");
                    printf("Impact Power: 0.07\n");

                    Vmin= random(0, Vb-50);
                    Vmax= random(Vmin,Vb);
                    printf("Minimum Angle: %d\n", min_ang_e);
                    printf("Maximum Angle: %d\n", max_ang_e);
                    min_ang_e = random(0,20);
                    max_ang_e = min_ang_e + 25;
                    printf("Minimum Velocity: %d\n", Vmin);
                    printf("Maximum Velocity: %d\n", Vmax);
                    fprintf(escort,"escortship %d : position: (%d,%d)\n", j, x, y);
                    fprintf(escort,"                            type Name: Matsu-class Destroyer\n");
                    fprintf(escort,"                            Gun Name: Type 89 dualpurpose gun\n");
                    fprintf(escort,"                            Impact Power: 0.07\n");
                    fprintf(escort,"                            Minimum Velocity: %d, Maximum Velocity - %d\n", Vmin, Vmax);
                    fprintf(escort,"                            Minimum Angle: %d\n,   Maximum Angle - %d\n", min_ang_e, max_ang_e);
                    printf("\n");
                    break;

                case 4:
                        printf("Esortship %d: \n", j);
                        printf("EscortShip Index: ED\n");
                        printf("EscortShip position : (%d,%d)\n",x, y);
                        printf("EscortShip Type: F-class Escort Ships\n");
                        printf("EscortShip Gun Name: SK C/32 naval gun\n");
                        printf("Impact Power: 0.05\n");

                        Vmin= random(0, Vb-50);
                        Vmax= random(Vmin,Vb);
                        min_ang_e = random(0,20);
                        max_ang_e = min_ang_e + 50;
                        printf("Minimum Velocity: %d\n", Vmin);
                        printf("Maximum Velocity: %d\n", Vmax);
                        printf("Minimum Angle: %d\n", min_ang_e);
                        printf("Maximum Angle: %d\n", max_ang_e);
                        fprintf(escort,"escortship %d : position: (%d,%d)\n", j, x, y);
                        fprintf(escort,"                            type Name: F-class Escort Ships\n");
                        fprintf(escort,"                            Gun Name: SK C/32 naval gun\n");
                        fprintf(escort,"                            Impact Power: 0.05\n");
                        fprintf(escort,"                            Minimum Velocity: %d, Maximum Velocity - %d\n", Vmin, Vmax);
                        fprintf(escort,"                            Minimum Angle: %d, Maximum Angle - %d\n", min_ang_e, max_ang_e);
                        printf("\n");
                        break;

                 case 5:
                            printf("Esortship %d: \n", j);
                            printf("EscortShip Index: EE\n");
                            printf("EscortShip position : (%d,%d)\n",x, y);
                            printf("EscortShip Type: Japanese Kaibōkan\n");
                            printf("EscortShip Gun Name: (4.7 inch) naval guns\n");
                            printf("Impact Power: 0.04\n");

                            Vmin= random(0, Vb-50);
                            Vmax= random(Vmin,Vb);
                            min_ang_e = random(0,20);
                            max_ang_e = min_ang_e + 70;

                            printf("Minimum Velocity: %d\n", Vmin);
                            printf("Maximum Velocity: %d\n", Vmax);
                            printf("Minimum Angle: %d\n", min_ang_e);
                            printf("Maximum Angle: %d\n", max_ang_e);
                            fprintf(escort,"escortship %d : position: (%d,%d)\n", j, x, y);
                            fprintf(escort,"                            type Name: Japanese Kaibōkan\n");
                            fprintf(escort,"                            Gun Name: (4.7 inch) naval guns\n");
                            fprintf(escort,"                            Impact Power: 0.04\n");
                            fprintf(escort,"                            Minimum Velocity: %d, Maximum Velocity - %d\n", Vmin, Vmax);
                            fprintf(escort,"                            Minimum Angle: %d, Maximum Angle - %d\n", min_ang_e, max_ang_e);
                            printf("\n");
                            break;
                            default:
                                printf("error");
                                break;
                                printf("\n");

    }

    // storing the escortship details in the array
    eship[j-1].maxVelocity = Vmax;
    eship[j-1].minVelocity = Vmin;
    eship[j-1].maxAngle = max_ang_e;
    eship[j-1].minAngle = min_ang_e;
    j++;
}
    //moving the battleship to different points
    int i = 1;
    srand(time(NULL) + i);
    int points = random(10,100); //generating the points randomly
    printf("Number of points the battleship move: %d\n", points);
    for(int k=1;k<=points;k++){

    int hitEscortships = 0; //Count the Number of escortships hit by the battleship

    //generating x and y coordinates of the battleship randomly
    int x_battle = random(0, canva_1-1);
    int y_battle = random(0, canva_2-1);

    printf("\n\nStimulating at point %d:(%d , %d)\n", k, x_battle, y_battle);


     //calling the array
     for(int count = 0; count < Escortships; count++) {
     // Skip processing if the Escortship has already been destroyed
     if (eship[count].impactPower <= 0.0) {
        continue;
     }
    int x = eship[count].coordinates[0];
    int y= eship[count].coordinates[1];
    int min_ang_e = eship[count].minAngle;
    int max_ang_e = eship[count].maxAngle;
    int Vmax = eship[count].maxVelocity;
    int Vmin = eship[count].minVelocity;

    //calculating the distance between the escortship and the battleship
    float distance = sqrt(pow(x_battle - x, 2) + pow(y_battle - y, 2));

   //converting the angles in degree to radians
   float rad1 = min_ang_e * (PI/180);
   float rad2 = max_ang_e * (PI/180);

  //Calculate the minimum range of the escortship
  float minrangeof_escort(int Vmin, float rad1, float g){
        return (pow(Vmin, 2)*(sin(2 * rad1)))/g;
        }
  float Rmin = minrangeof_escort(Vmin, rad1, g);

  //Calculate the maximum range of the escortship
  float maxrangeof_escort(int Vmax, float rad2, float g){
       return (pow(Vmax, 2)*(sin(2 * rad2)))/g;
       }
  float Rmax = maxrangeof_escort(Vmax, rad2, g);

  // Check if the distance is within the maximum range of the escort ship's guns
  if (distance <= Rmax && distance >= Rmin) {
    printf("Escortship %d sinks the battleship.\n", count+1);
    sankBattleship = 1;

    saveBattlefieldConditions(Escortships, x_battle, y_battle, canva_1, canva_2);
    simulationResults(x_battle, y_battle, hitEscortships);

  break;
}  else{
     printf("Battleship hits the Escortship %d!\n", count+1);
     hitEscortships++;
     eship[count].impactPower = 0.0;

     }
     //calculating the time taken to hit the escortship by the battleship
     float angle_of_elevation = atan((float)(y - y_battle) / (float)(x - x_battle));
     float Vx = Vb * cos(angle_of_elevation);
     float time_to_hit = (float)distance / Vx;


     total_time = total_time +time_to_hit; // total time taken to end the battle


     printf("Battleship hits the Escortship %d in %.2f seconds\n", count+1, time_to_hit);

      //storing the details of the destroyed eship in a text file
      FILE *escortshipFile = fopen("Destroyed_Eship_details.txt", "w");
      if(escortshipFile == NULL){
        printf("Error opening file for writing.\n");
        return;
      }
        //details of the destroyed escort ships
        fprintf(escortshipFile, "Index of E: %d\n", count+1);
        fprintf(escortshipFile, "Time to hit: %f\n", time_to_hit);

      fclose(escortshipFile);

      saveBattlefieldConditions(Escortships, x_battle, y_battle, canva_1, canva_2);
      simulationResults(x_battle, y_battle, hitEscortships);
}


    printf("Number of Escortships hit by the Battleship: %d\n", hitEscortships);
    }
     printf("Total time to end the battle: %.2f seconds\n", total_time);
   fclose(escort);



return 0;
}
 void saveBattlefieldConditions(int Escortships, int x_battle, int y_battle, int canva_1, int canva_2) {
    FILE *battlefieldFile = fopen("battlefield_conditions.txt", "w");
    if (battlefieldFile == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
      // final conditions of the battlefield to the file
    fprintf(battlefieldFile, "Final Conditions of the Battlefield:\n");
    fprintf(battlefieldFile, "Battleship Position: (%d, %d)\n", x_battle, y_battle);
    fprintf(battlefieldFile, "Canvas Dimensions: %d x %d\n", canva_1, canva_2);
    fprintf(battlefieldFile, "Number of Escortships: %d\n", Escortships);

fclose(battlefieldFile);
 }
 void simulationResults(int x_battle, int y_battle, int hitEscortships){
     FILE *simulationFile = fopen("Simulation Results", "w");
     if(simulationFile == NULL){
        printf("Error opening the file");
        return 1;
     }
     //simulation results
     fprintf(simulationFile, "Battleship position: (%d, %d\n", x_battle, y_battle);
     fprintf(simulationFile, "No of escortships hit by the battleship: %d\n", hitEscortships);

fclose(simulationFile);
 }
