/*
	 Programmer: Fabrice Kouonang
	 Date:       22/10/2024
	 But:        Le programme gere la location de vehicule.
				 Il demande des informations sur le nom du client, le type de vehicule loue et le nombre de jours
				 puis calcule et affiche le montant a payer.

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Liste des constantes

const double   PU_LOCATION_AUTO              = 35.0;
const double   PU_LOCATION_FOURGO            = 40.0;
const double   PU_LOCATION_CAMION            = 45.0;
const double   POURCENT_RABAIS_3J            = (double)10/100;
const double   POURCENT_RABAIS_TOTAL         = (double)5/ 100;
const unsigned short NOMBRE_JOURS_MIN_RABAIS = 3;
const double   TOTAL_LOCATION_RABAIS_5       = 400.0;

int main(void)
{

	//Liste des inputs du programmes
	unsigned short nbreJourLocation = 0;
	string   nomClient              = "";
	char     typeVehicule           = ' ';

	//Liste intermedieres
	double prixApplicable = 0.0;

	//Liste des outputs
	double boni = 0.0;
	double totalVente = 0.0;
	string libelleVehicule = "";
	double commission = 0.0;
	double montantTtc = 0.0; //Montant toutes taxes inclusses

	cout << "\t\tLOCATION de vehicules ROY LTD."
		<< endl << endl
		<< fixed << setprecision(2);

	//Recuperation des data et premier affichage pour l'utilisateur
	cout << "Indiquez le type de vehicule par: "
		<< endl
		<< "A pour auto,"
		<< endl
		<< "F pour fourgonnette ou "
		<< endl
		<< "C pour camion"
		<< endl<<endl
		<< " Quel est le type de vehicule ? ";
	cin >> typeVehicule;

	cout << endl 
		<< "Donnez le nombre de jours de location:  ";
	cin >> nbreJourLocation;
	cin.ignore(); //pour permettre affichage de la donnee recuperee depuis le getline()
	cout << endl
		 << "Entrez votre nom :  ";
	getline(cin, nomClient);


	//calcul et 2eme affichage
	//recherche des prix par vehicule et type vehicule selon le char
	switch (toupper(typeVehicule))
	{
	case 'A':
		prixApplicable = PU_LOCATION_AUTO;
		libelleVehicule = "Auto";
		break;
	case 'F':
		prixApplicable = PU_LOCATION_FOURGO;
		libelleVehicule = "Fourgonnette";
		break;
	default:
		prixApplicable = PU_LOCATION_CAMION;
		libelleVehicule = "Camion";
		break;

	}

	montantTtc = nbreJourLocation * prixApplicable;

	if ((toupper(typeVehicule) == 'F' || toupper(typeVehicule) == 'C') && nbreJourLocation > NOMBRE_JOURS_MIN_RABAIS)
		montantTtc = montantTtc * (1 - POURCENT_RABAIS_3J);

	if(montantTtc>TOTAL_LOCATION_RABAIS_5)
		montantTtc = montantTtc * (1 - POURCENT_RABAIS_TOTAL);

	cout << endl << endl
		<< nomClient
		<< endl 
		<< "Votre location de vehicule de type : "
		<< libelleVehicule
		<< endl
		<< "d'une duree de  "
		<< nbreJourLocation
		<< " jours vous coutera: "
		<< montantTtc <<" $"
		<< endl << endl;

	system("pause");
	return 0;
}
