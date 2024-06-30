#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
#ifdef WRITE_TO_FILE
	setlocale(LC_ALL, "");
	cout << "HelloWorld" << endl;
	std::ofstream fout;//создаем поток  
	fout.open("File.txt", std::ios_base::app); //открываем поток(append  дописать конец файла)
	//fout << "HelloWorld" << endl;//пишем в поток
	time_t now = time(NULL);
	fout << ctime(&now) << endl;
	fout.close();//закрываем поток 
	system("notepad File.txt");
#endif // WRITE_TO_FILE
	//Создаем и открываем поток 
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Здесь будем читать файл 
		const int SIZE = 256; //размер буффера
		char buffer[SIZE]{};//буффер 

		while (!fin.eof())//NOT EndofFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);//Читает строку с пробелами 
			cout << buffer << endl; 
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:File not found" << endl;
	}
	
}