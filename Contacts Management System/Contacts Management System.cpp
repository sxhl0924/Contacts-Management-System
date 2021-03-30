#include<iostream>
using namespace std;
#include<string>
# define Max 1000 //define a constant variant for easy maintanance

//create a structure for persons in the contacts
struct Person
{
	//name
	string m_Name;
	//sex 1. male 2. female
	int m_Sex = 0;
	//age
	int m_Age = 0;
	//phone number
	string m_Phone;
	//address
	string m_Address;
};

//creat a structure for contacts
struct Contacts
{    
	//Array of persons in contacts
	struct Person personArray[Max];//define a constant variant Max for easy maintanance
	//number of persons in contacts
	int m_Size = 0;
};


//create a showMenu function to display the menu page
void showMenu()
{
	cout << "***************************************" << endl;
	cout << "******** 1. Add a new person   ********" << endl;
	cout << "******** 2. Show contacts      ********" << endl;
	cout << "******** 3. Delete a person    ********" << endl;
	cout << "******** 4. Find a person      ********" << endl;
	cout << "******** 5. Modify a person    ********" << endl;
	cout << "******** 6. Clear all contacts ********" << endl;
	cout << "******** 0. Logout contacts    ********" << endl;
	cout << "***************************************" << endl;
}


//1. creat a function to add a new person in contacts
void addPerson(Contacts * contact)
{
	//check whether the contact is full or not
	if (contact->m_Size == Max)
	{
		cout << "The contacts are full! New person cannot be added." << endl;
		return;
	}
	else
	{
		//add new person
		//name		
		cout << "Plese input First name: " << endl;
		string f_name;
		cin >> f_name;
		cout << "Please input Last name: " << endl;
		string l_name;
		cin >> l_name;
		contact->personArray[contact->m_Size].m_Name = f_name +" "+ l_name;
		//sex
		int sex = 0;
		cout << "1---Male" << endl;
		cout << "2---Female" << endl;
		cout << "Please input a sex: " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				contact->personArray[contact->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "Input error! Please input a correct sex." << endl;
			}
		}
		//age
		cout << "Please input an age: " << endl;
		int age = 0;
		cin >> age;
		contact->personArray[contact->m_Size].m_Age = age;
		//phone
		cout << "Please input a phone number: " << endl;
		string phone;
		cin >> phone;
		contact->personArray[contact->m_Size].m_Phone = phone;
		//address
		cout << "Please input an address: " << endl;
		string address;
		cin >> address;
		contact->personArray[contact->m_Size].m_Address = address;
		//update the number of persons in personArray
		contact->m_Size++;

		cout << "Added successfully!" << endl;

		system("pause");
		system("cls");//clear the screen
	}
}

//2. creat a function to show the contact information of a person
void showPerson(Contacts * contact)
{
//check whether  contacts are empty or not
	if (contact->m_Size == 0)
	{
		cout << "Contacts Empty!" << endl;
	}
	else
	{
		for (int i = 0; i < contact->m_Size; i++)
		{
			cout << "Name: " << contact->personArray[i].m_Name<<"\t";
			cout << "Sex: " << (contact->personArray[i].m_Sex == 1?"Male":"Female") << "\t";
			cout << "Age: " << contact->personArray[i].m_Age << "\t";
			cout << "Phone: " << contact->personArray[i].m_Phone << "\t";
			cout << "Address: " << contact->personArray[i].m_Address << endl;
		}		
	}	
	system("pause");
	system("cls");
}

//create a function to check whether a person exists in contacts or not
int isExsit(Contacts * contact, string name)
{
	for (int i = 0; i < contact->m_Size; i++)
	{
		if (name == contact->personArray[i].m_Name)
		{
			return i;
		}
	}
	return -1;
}

//3. create a function to delete a person
void deletePerson(Contacts * contact)
{
	cout << "Please input the name of person you want to delete: " << endl;
	cout << "First name: " << endl;
	string f_name;
	cin >> f_name;
	cout << "Last name: " << endl;
	string l_name;
	cin >> l_name;
	string name = f_name + " " + l_name;

	int Result = isExsit(contact, name);

	if (Result != -1)
	{
		for (int i = Result; i < contact->m_Size; i++)
		{
			//move forward the data by one step to delete the input person
			contact->personArray[i] = contact->personArray[i + 1];
		}
		contact->m_Size--;//update the number of persons in contacts
		cout << "Delete Successfully!" << endl;
	}
	else
	{
		cout << "Person dose not exist!" << endl;
	}
	system("pause");
	system("cls");
}

//4. create a function to find a person in contacts
void findPerson(Contacts * contact)
{
	cout << "Please input the person you want to find: " << endl;
	cout << "First name: " << endl;
	string f_name;
	cin >> f_name;
	cout << "Last name: " << endl;
	string l_name;
	cin >> l_name;
	string name = f_name + " " + l_name;

	int Result = isExsit(contact, name);
	//check whether a person exists or not
	if (Result != -1)
	{
		cout << "Name: " << contact->personArray[Result].m_Name <<"\t";
		cout << "Sex: " << (contact->personArray[Result].m_Sex == 1 ? "Male" : "Female") <<"\t";
		cout << "Age: " << contact->personArray[Result].m_Age <<"\t";
		cout << "Phone: " << contact->personArray[Result].m_Phone <<"\t";
		cout << "Address: " << contact->personArray[Result].m_Address <<endl;
	}
	else
	{
		cout << "Person cannot be found!" << endl;
	}
	system("pause");
	system("cls");

}

//5. create a function to modify a person in contacts
void modifyPerson(Contacts * contact)
{
	cout << "Please input the name of person you want to modify: " << endl;
	cout << "First name: " << endl;
	string f_name;
	cin >> f_name;
	cout << "Last name: " << endl;
	string l_name;
	cin >> l_name;
	string name = f_name + " " + l_name;
	int Result = isExsit(contact, name);
	if (Result != -1)//person exists in contacts
	{
		//modify name
		string name;
		cout << "Please modify the name: " << endl;
		cin >> name;
		contact->personArray[Result].m_Name = name;
		//modify sex	
		int sex = 0;
		cout << "Please modify the sex: " << endl;
		cout << "1---Male" << endl;
		cout << "2---Female" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				contact->personArray[Result].m_Sex = sex;
				break;
			}
			else
			{
				cout << "Input error! Please input a correct sex. " << endl;
			}
		}
		//modify age
		cout << "Please modify the age: " << endl;
		int age;
		cin >> age;
		contact->personArray[Result].m_Age = age;
		//modify phone
		cout << "Please modify the phone: " << endl;
		string phone;
		cin >> phone;
		contact->personArray[Result].m_Phone = phone;
		//modify address
		cout << "Please modify the address: " << endl;
		string address;
		cin >> address;
		contact->personArray[Result].m_Address = address;

		cout << "Modify Successfully!" << endl;
	}
	else
	{
		cout << "Person cannot be found!" << endl;
	}
		
	system("pause");
	system("cls");
}

//6. create a function to clear entire contacts
void clearContacts(Contacts * contact)
{
	cout << "You are going to clear all contacts! Are you sure?" << endl;
	cout << "1---Yes, continue to clear all." << endl;
	cout << "2---No, give up clearing." << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		contact->m_Size = 0;
		cout << "Contacts have been clear!" << endl;
	}

	system("pause");
	system("cls");
}

int main()
{
	//creat a variant of Contacts structure
	Contacts contact;
	//initialize the value of m_Size of contact
	contact.m_Size = 0; 

	int select = 0; //creat a variant to store the user's selection
	while (true)
	{
		showMenu(); //run showMenu fuction
		cout << "Please select a function: " << endl;
		cin >> select;

		switch (select)
		{
		case 1://1. Add a new person in contacts
			addPerson(&contact);
			break;
		case 2://2. Show all persons in contacts
			showPerson(&contact);
			break;
		case 3://3. Delete a person in contacts
			deletePerson(&contact);
			break;
		case 4://4. Find a person in contacts
			findPerson(&contact);
			break;
		case 5://5. Modify a person in contacts
			modifyPerson(&contact);
			break;
		case 6://6. Clear contacts
			clearContacts(&contact);
			break;
		case 0://0. Logout contacts
			cout << "Thanks for using!" << endl;
			break;			
		default:
			break;

		system("pause");
		return 0;
		
		}
	}

	system("pause");
	return 0;
}