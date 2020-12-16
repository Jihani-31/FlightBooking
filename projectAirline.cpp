#include<fstream>
#include<iostream>
#include <sstream>     //for istringstream function
#include<string>//to store everyline
using namespace std;

struct seat{ //create struct for seat
	string row;
	string clz;
	string ar;
};

class flight{
	public:                                                                        
		string flightNo;
		string dateAndTime;
		string deAirport;
		string arAirport;
		int noBcls; // no Business class seats
		int noEcls; // no Economic class seats
		int rows;
		seat st[100];  //create structure array
		
	
		
};

	flight flightArray[1000]; //initialize class array
	int count; // Number of flight in the file

	int getFlightCount(){ //to get number of flight
		ifstream file("flights.txt");  //open file for reading
		string ch;
		int i=0;
		int count=0;
		while(getline(file,ch)!=NULL){ // run until the line is not empty
			if(i==0){
				if(!ch.empty()){  
					count++;
					i++;   //if line is not empty increase i value
				}
			}
			else{
				if(ch.empty()){  
					i++;
					getline(file,ch);
					if(!ch.empty()){
						count++;
						i++;
					}
					else{
						i++;
					}
					
				}
				else{
					i++;
				}
			}
		}
		return count;
	}
	
void display(){// option one
	
	int i;
	for(i=0;i<count;i++){
		cout<<endl<<"Flight number: "<<flightArray[i].flightNo;                     //show details of flights
		cout<<endl<<"Departure date and time: "<<flightArray[i].dateAndTime;
		cout<<endl<<"Arrival airport code: "<<flightArray[i].arAirport;
		cout<<endl<<"Departure airport code: "<<flightArray[i].deAirport;
		cout<<endl<<"-------------------------------------------";
	}
}
void searchFlight(){// option two
	string flightNo;
	cout<<endl<<"Enter the Flight number  :";
	cin>>flightNo;
	int available;
	int i;
	int n; // which flight on the text
	for(i=0;i<count;i++){
		if(flightNo == flightArray[i].flightNo){ //check if it's the flight available
			n = i;  
			available = 1;
			break;   //when the flight is find exit for loop
		}
	}
	if(available == 1){   //if flight is available print flight detail
		cout<<endl<<"Flight number: "<<flightArray[i].flightNo;
		cout<<endl<<"Departure date and time: "<<flightArray[i].dateAndTime;
		cout<<endl<<"Arrival airport code: "<<flightArray[i].arAirport;
		cout<<endl<<"Departure airport code: "<<flightArray[i].deAirport;
		int available;
	
		int j;
		int i;
		int n; // which flight on the text
		for(i=0;i<count;i++){
			if(flightNo == flightArray[i].flightNo){
				n = i;
				available = 1;
				break;
			}
		}
		flightArray[n].noEcls = 0;  //to keep the economic clz count
		flightArray[n].noBcls = 0; //to keep the business clz count
		for(j=0;j<60;j++){
			if(flightArray[n].st[j].clz == "B"){  //check if the class is business class
				flightArray[n].noBcls = flightArray[n].noBcls + flightArray[n].st[j].ar.length();  //to get number of seats available in business class
			}else{
				flightArray[n].noEcls = flightArray[n].noEcls + flightArray[n].st[j].ar.length();   //to get number of seats available in economical class
			}
		
		}
		cout<<endl<<"Available Economic class seats : "<<flightArray[n].noEcls;    //print available economical clz
		cout<<endl<<"Available Business class seats : "<<flightArray[n].noBcls;    //print  available business clz
	}else{
		cout<<endl<<"Sorry, that flight is not available..."; //if searched flight is not available
	}
}
void availableSeats(){// option three
	string flightNo;
	cout<<endl<<"Enter the Flight number  :";
	cin>>flightNo;
	int noOfSeats;
	cout<<endl<<"Enter the required number of seats  :";
	cin>>noOfSeats;
	int available;
	int noOfAvailableSeats;
	
	int j;
	int i;
	int n; // which flight on the text
	for(i=0;i<count;i++){
		if(flightNo == flightArray[i].flightNo){
			n = i;
			available = 1;
			break;
		}
	}
	flightArray[n].noEcls = 0;   //to keep economical class count
	flightArray[n].noBcls = 0;  //to keep business class count
	for(j=0;j<60;j++){
		if(flightArray[n].st[j].clz == "B"){
			flightArray[n].noBcls = flightArray[n].noBcls + flightArray[n].st[j].ar.length(); //call length function to find seats
		}else{
			flightArray[n].noEcls = flightArray[n].noEcls + flightArray[n].st[j].ar.length();
		}
		
	}
	
	noOfAvailableSeats = flightArray[n].noEcls + flightArray[n].noBcls; //gets total number of seats
	if(available == 1){
		if(noOfSeats > noOfAvailableSeats){  //check number of required seats greater than available seat
			cout<<endl<<"Sorry, it's available only, ";
			cout<<endl<<"Business class : ";
			cout<<flightArray[n].noBcls;                    //print available economic  class seats
			cout<<endl<<"Economic class : ";
			cout<<flightArray[n].noEcls;   //print available economic  class seats
		}else{        //if seats are available
			cout<<endl<<"it's available.....";
			cout<<endl<<"Available Business class seats  : "<<flightArray[n].noBcls;
			for(j=0;j<60;j++){
				if(flightArray[n].st[j].clz == "B"){
					cout<<endl<<flightArray[n].st[j].row<<"  "<<flightArray[n].st[j].clz<<" "<<flightArray[n].st[j].ar;
					//print seat details of business class
				}
			}
			cout<<endl<<"Available Economic class seats  : "<<flightArray[n].noEcls;
			for(j=0;j<60;j++){
				if(flightArray[n].st[j].clz == "E"){
					cout<<endl<<flightArray[n].st[j].row<<"  "<<flightArray[n].st[j].clz<<" "<<flightArray[n].st[j].ar;  
					 //print seat details of economic class
				}
			}
		}
	}else{
		cout<<endl<<"Sorry, that flight is not available..."; //if searched flight is not available
	}
	
}
void bookingSeats(){// option four
	string flightNo;
	string row;
	string column;
	cout<<endl<<"Enter the Flight number  :";
	cin>>flightNo;
	int available;
	int booked;
	int i;
	int n; // which flight on the text
	int k;
	for(i=0;i<count;i++){ // check is it available or not 
		if(flightNo == flightArray[i].flightNo){
			n = i;
			available = 1;
			break;
		}
	}
	if(available == 1){
		cout<<endl<<"--- The seat location ---";
		cout<<endl<<"Enter the row number of seat  :";
		cin>>row;
		cout<<endl<<"Enter the column letter of seat  :";
		cin>>column;
		for(k=0;k<=60;k++){
			
			if(flightArray[n].st[k].row==row){   //check if the entered row
				if(flightArray[n].st[k].ar.find(column)!=string::npos){     //to check column
					flightArray[n].st[k].ar.erase(flightArray[n].st[k].ar.find(column),1); //delete booked seat
					booked = 1;
					break;
				}else{
					booked = 0;
				}
				
			}
			
		}
		
		if(booked == 1){
			cout<<endl<<"The seat is Booked";
			cout<<endl<<"- Thank you -";
		}else{
			cout<<endl<<"Sorry, the selected seat is not available";
		}
			
	}else{
		cout<<endl<<"Sorry, that flight is not available..."; //if searched flight is not available
	}
}


void exitBooking(){
	
	ofstream newFile("flights.txt"); //insert  flight update details
	for(int i=0;i<count;i++){
		int k=0;
		newFile<<flightArray[i].flightNo<<endl;
		newFile<<flightArray[i].dateAndTime<<endl;
		newFile<<flightArray[i].deAirport<<endl;        //write data into file
		newFile<<flightArray[i].arAirport<<endl;
		while(1){
			if(flightArray[i].st[k].row==""){
				break;
			}
			else{
				newFile<<flightArray[i].st[k].row<<" "<<flightArray[i].st[k].clz<<" "<<flightArray[i].st[k].ar<<endl;
			}
			
			k++;
		}
		newFile<<endl;
	}newFile.close();
	exit(0);
}
	
	
	
	
	

int main(){
	int option;
	
	count=getFlightCount();  //get the number of flight and it assign to count
	string line;
	
	ifstream file("flights.txt");
	
	
	//cout<<"No Of Flight : "<<count<<endl; 
	
	int seatsnum=0; //to keep seat number
	seat st[100];
	
	int i;
	int x=0;
	for(i=0;i<count;i++){
	string line;			
	int c=0;
	while(!file.eof()){
     getline(file,line); 
		
	if(!line.empty()){  //check text file line is not empty
		
	if(c==0){
		flightArray[i].flightNo=line;
	
		c++;
	}
	else if(c==1){
	   flightArray[i].dateAndTime=line;
	
	   c++;
	}
	else if(c==2){
		flightArray[i].arAirport=line;
	
		c++;
	}
	else if (c==3){
		flightArray[i].deAirport=line;
	
		c++;
		
	}
	else if(c>=4){
			
		//ft[i].seats[seatsnum]=line;
		
		istringstream ss(line);
		ss >> flightArray[i].st[seatsnum].row >> flightArray[i].st[seatsnum].clz >> flightArray[i].st[seatsnum].ar;
		
	
		c++;
		seatsnum++;
	
	}
		}else
		{
			c=0;
			i++;
			seatsnum=0;
		}
			
	}
	}
		
	    int run = 1;
    while(1){
    	cout<<endl<<"------ MAIN MENU ------"<<endl<<endl;  
		cout<<endl<<"1. Display available flights";
		cout<<endl<<"2. View flight";
		cout<<endl<<"3. Seat availability";
		cout<<endl<<"4. Seat booking";
		cout<<endl<<"5. Exit"<<endl<<endl;
		cout<<endl<<"Enter an option:";  //take choice from user
		cin>>option;
		bool ignore=false;
		while(!cin)   //check option is string
		{
			if(!ignore)   
			{
				cout<<"it's not a integer....."<<endl;
				cout<<"please enter an integer:"<<endl;
				ignore=true;
				
			}
			
			cin.clear(); 
			cin.ignore();
			cin>>option;
		}
		
		
		switch(option){
			case 1: 
				display();   //call display function to display flights details
				break;
			case 2:
				searchFlight();  //call searchFlight  function
				break;
			case 3:
				availableSeats();      //call availableSeats function
				break;
			case 4:
				bookingSeats();      //call bookingSeats function
				break;
			case 5:
				run = 0;
				
				exitBooking();
				break;
			default:    
				cout<<endl<<"Wrong option ";
				
				break;
				
			
		}
	}
	
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

