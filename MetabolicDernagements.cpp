#include <iostream>
#include <string>

using namespace std;

class Patient{
    public:
        string name;
        string ABstate;
        string Cause;
        string timing;
        bool Compensated;
        double pH;
        double AG;
        double PaCO2;
        double HCO3;
        double deltaRatio;
        
        
};


int main(){ 

    Patient Patient1;
    string name;
    cout << "Input the patient's name: ";
    cin >> name;
    Patient1.name = name;
    //Step 1 Calculate the pH (Acidosis vs Alkalosis)

    cout << "Hello " << Patient1.name << "'s Doctor, what is " << Patient1.name << "'s ABG pH? ";
    double pH;
    cin >> pH;
    Patient1.pH = pH;
    cout << Patient1.name << "'s ABG pH is " <<  Patient1.pH << endl ;
    
    if (Patient1.pH < 7.35){
        Patient1.ABstate = "Acidosis";
        cout << Patient1.name << " is acidotic since their pH of " <<  Patient1.pH << " is below 7.35" << endl ;
    };
    
    if (Patient1.pH >= 7.35 & Patient1.pH <= 7.45){
        Patient1.ABstate = "Normal";
        cout << Patient1.name << " has a normal or compenstaed pH since their pH of " <<  Patient1.pH << " is between 7.35 and 7.45" << endl ;
    };

    if (Patient1.pH > 7.45){
        Patient1.ABstate = "Alkalosis";
        cout << Patient1.name << " is alkalotic since their pH of " <<  Patient1.pH << " is above 7.45" << endl ;
    }; 

    //Step 2 Determine Respiratory vs Metabolic

    cout << "what is " << Patient1.name << "'s blood paCO2? ";
    double PaCO2;
    cin >> PaCO2;
    Patient1.PaCO2 = PaCO2; 

    cout << "what is " << Patient1.name << "'s blood HCO3? ";
    double HCO3;
    cin >> HCO3;
    Patient1.HCO3 = HCO3; 

    if (Patient1.ABstate == "Acidosis" && Patient1.HCO3 < 24 ){
        Patient1.Cause = "Metabolic" ; 
        cout << Patient1.name << " is has a metabolic acidosis since their pH of " <<  Patient1.pH << " is below 7.35 and their Bicarb of " <<  Patient1.HCO3 << " is < 24" << endl ;
    };

    if (Patient1.ABstate == "Acidosis" && Patient1.PaCO2 > 40){
        Patient1.Cause = "Respiratory" ; 
        cout << Patient1.name << " is has a respiratory acidosis since their pH of " <<  Patient1.pH << " is below 7.35 and their PaCO2 of " <<  Patient1.PaCO2 << " is > 40" << endl ;
    };

    if (Patient1.ABstate == "Alkalosis" && Patient1.HCO3 > 24 ){
        Patient1.Cause = "Metabolic" ; 
        cout << Patient1.name << " is has a metabolic alkalosis since their pH of " <<  Patient1.pH << " is below 7.45 and their Bicarb of " <<  Patient1.HCO3 << " is > 24" << endl ;
    
    };

    if (Patient1.ABstate == "Alkalosis" && Patient1.PaCO2 < 40){
        Patient1.Cause = "Respiratory" ; 
        cout << Patient1.name << " is has a respiratory alkalosis since their pH of " <<  Patient1.pH << " is above 7.45 and their PaCO2 of " <<  Patient1.PaCO2 << " is < 40" << endl ;
    
    };

    //Step 3 Calculate the Anion Gap

    cout << "what is " << Patient1.name << "'s Anion Gap? ";
    double AG;
    cin >> AG;
    Patient1.AG = AG; 


    if (Patient1.AG > 12){
        cout << Patient1.name << " has an elevated anion gap " << Patient1.Cause << " " << Patient1.ABstate << endl;

        Patient1.deltaRatio = (Patient1.AG - 12)/(24 - Patient1.HCO3);
    
        cout << Patient1.name << " has a delta ratio of " << Patient1.deltaRatio <<endl;

        if (Patient1.deltaRatio <= 0.4){
        cout << Patient1.name << " ALSO has a Normal Anion Gap Metabolic acidosis" << endl;
        }

        if (Patient1.deltaRatio >= 0.4 && Patient1.deltaRatio <= 0.8){
            cout << Patient1.name << " has a Normal Anion Gap Metabolic acidosis and a Raised Anion Gap Metabolic Acidosis" << endl ;
        }

        if (Patient1.deltaRatio >= 0.8 && Patient1.deltaRatio < 2){
            cout << Patient1.name << " ONLY has a raised Anion Gap Metabolic Acidosis" << endl;
        }

        if (Patient1.deltaRatio >= 2){
            cout << Patient1.name << " has a concurrent Metabolic Alkalosis" << endl ;
        }
    };

    if (Patient1.AG <= 12){ 
        cout << Patient1.name << " does NOT have an elevated anion gap" << endl;
    };



    //Step 4 Determine the compensation

    //Winters formula Met acid

    cout << "Checking for Compensation... " << endl;

    if (Patient1.ABstate == "Acidosis" && Patient1.Cause == "Metabolic") {
        cout << "Winters Fomula: PCO2 (within 2 mm Hg) = 1.5 (HCO3) + 8 " << endl;
        if (abs((1.5 * Patient1.HCO3) + 8 - Patient1.PaCO2) <= 2.1) {
            Patient1.Compensated = true ;
            cout << "Metabolic Acidosis is compensated" << endl;
            cout << "1.5 x " << Patient1.HCO3 << " + 8 = " << 1.5 * Patient1.HCO3 + 8 <<  ", which +/-2 = "  << Patient1.PaCO2 << endl; 
        }
        else {
            Patient1.Compensated = false;
            cout << "Metabolic Acidosis is NOT compensated" << endl;
        }
    }

    // Resp Acidosis response
    if (Patient1.ABstate == "Acidosis" && Patient1.Cause == "Respiratory") {
        cout << "Was the acidosis Acute or Chronic? " << endl;
        cin >>  Patient1.timing;
        if (Patient1.timing == "Acute" || Patient1.timing == "acute"){
            cout << "In Acute Respiratory acidosis, for 10 mmHg increase in the PCO2, there should be a 1 meq/L increase in HCO3 " << endl;
            if (abs((Patient1.PaCO2 - 40) - (10 * (Patient1.HCO3 - 24))) < 5 ){
                Patient1.Compensated = true ;
                cout << "Acute Respiratory Acidosis is compensated" << endl;
            }
        
            else {
                Patient1.Compensated = false;
                cout << "Acute Respiratory Acidosis is NOT compensated" << endl;
            }
        }
        
        else { 
            cout << "In Chronic Respiratory Acidoisis, for every 10 mmHg increase in the PCO2, there should be a 4 meq/L increase HCO3 " << endl;
            if (abs((Patient1.PaCO2 - 40) - (4 * (Patient1.HCO3 - 24 ))) < 5 ){
                Patient1.Compensated = true;
                cout << "Chronic Respiratory Acidosis is compensated" << endl;
            }
            else {
                Patient1.Compensated = false;
                cout << "Chronic Respiratory Acidosis is NOT compensated" << endl ;
            }
        } 

    }
    
    // Met alk comp
    if (Patient1.ABstate == "Alkalosis" && Patient1.Cause == "Metabolic") {
        cout << "For every 1 meq/L increase in HCO3, PCO2 should increase by 0.7 mm Hg" << endl;
        if (abs((Patient1.HCO3 - 24) - (0.7 * Patient1.PaCO2 - 40)) < 5 ) {
            Patient1.Compensated = true ;
            cout << "Metabolic Alkalosis is compensated" << endl ;
        }
        else {
           Patient1.Compensated = false;
           cout << "Metabolic Alkalosis is NOT compensated" << endl ; 
        }
    }
    
    // Met alk Resp
    if (Patient1.ABstate == "Alkalosis" && Patient1.Cause == "Respiratory"){
        cout << "Was the Alkalosis Acute or Chronic? " << endl;
        cin >>  Patient1.timing;
        if (Patient1.timing == "Acute" || Patient1.timing == "acute"){
            cout << "In Acute Resp Alkalosis, for every 10 mmHg decrease in the PCO2, there should be a 2 meq/L decrease HCO3" << endl;
            if (abs((40 - Patient1.PaCO2) - (2 * (24 - Patient1.HCO3)))< 5 ){
                Patient1.Compensated = true ;
                cout << "Acute Respiratory Alkalosis is compensated" << endl;
            }
        
            else {
                Patient1.Compensated = false;
                cout << "Respiratory Alkalosis is NOT compensated" << endl ;
            }
        }
        
        else { 
            cout << "In Chronic Respiratory Alkalosis, for every 10 mmHg decrease in the PCO2, there should be a 4 meq/L decrease HCO3" << endl;
            if (abs((40 - Patient1.PaCO2) - (4 * (24- Patient1.HCO3))) < 5 ){
                Patient1.Compensated = true;
                cout << "Chronic Respiratory Alkalosis is compensated" << endl;
            }
            else {
                Patient1.Compensated = false;
                cout << "Respiratory Alkalosis is NOT compensated" << endl ;
            }
        } 

    }


    //Step 5 IF AG metabolic acidosis, consider additional metabolic alk or non-ag met acidosis








    return 0;
}