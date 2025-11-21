//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include <tchar.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <bitset>
#pragma argsused
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//инициализируем буффер
unsigned int buffer[4];

int zeroPadding;
//вспомогательные функции для 4 пункта
unsigned int F(unsigned int X, unsigned int Y, unsigned int Z)
{
	return (X & Y) | (~X & Z);
}

unsigned int G(unsigned int X, unsigned int Y, unsigned int Z)
{
	return (X & Z) | (Y & ~Z);
}

unsigned int H(unsigned int X, unsigned int Y, unsigned int Z)
{
	return X ^ Y ^ Z;
}

unsigned int I(unsigned int X, unsigned int Y, unsigned int Z)
{
	return Y ^ (X | ~Z);
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
UnicodeString input = Memo1->Text;
System::DynamicArray<Byte> bytes = WideBytesOf(input); //танцы с бубном для преобразования в байты

bytes.Length += 1;
bytes[bytes.Length - 1] = 0x80; // добавляем единичный бит 1

int blockSize = 512; // размер блока
int targetLength = (bytes.Length * 8 + 448) % blockSize; //  кол-во нулей для дописывания
 zeroPadding = targetLength; // кол-во нулевых битов для дописывания (по сути это L)

bytes.Length += zeroPadding / 8;
// дописываем нулевые байты
for (int i = 0; i < zeroPadding / 8; i++)
{
	bytes[bytes.Length - zeroPadding / 8 + i] = 0x00;
}

//вывод в формате little-endian(младший байт хранится по меньшему адресу, а старший байт– по большему, что является обратным порядком от того, как мы читаем число)
UnicodeString output;
for (int i = bytes.Length - 1; i >= 0; --i) {
	output += IntToHex(bytes[i], 2); //позволяет преобразовать каждый байт в 16-е представление с фиксированной длинной 2 символа для вывода
}

Memo2->Text = output;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
UnicodeString message = Memo1->Text;
	UnicodeString hexOutput = Memo2->Text;

	//+в конец сообщения 64-битную длинну исходного сообщения
   //	__int64 length = message.Length() * sizeof(wchar_t) * 8;
   //	hexOutput += IntToHex(length & 0xFFFFFFFF, 8);
   //	hexOutput += IntToHex((length >> 32) & 0xFFFFFFFF, 8);

// получение младших 64 бит из побитового представления длины сообщения
__int64 length = message.Length() * sizeof(wchar_t) * 8;
uint32_t lowerBits = length & 0xFFFFFFFF;
uint32_t upperBits = (length >> 32) & 0xFFFFFFFF;

// добавление младших 4 байт
hexOutput += IntToHex(static_cast<int>(lowerBits & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((lowerBits >> 8) & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((lowerBits >> 16) & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((lowerBits >> 24) & 0xFF), 2);

// добавление старших 4 байт
hexOutput += IntToHex(static_cast<int>(upperBits & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((upperBits >> 8) & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((upperBits >> 16) & 0xFF), 2);
hexOutput += IntToHex(static_cast<int>((upperBits >> 24) & 0xFF), 2);
	Memo3->Text = hexOutput;

 //инициализируем буффер значенияими по условию
unsigned int buffer[4] = { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 };

//чтобы можно было выводить в Мемо по человечески + записываем начальное значение в буффер
//buffer[0] = StrToInt("0x" + hexOutput.SubString(1, 8));
 //	buffer[1] = StrToInt("0x" + hexOutput.SubString(9, 8));
  //	buffer[2] = StrToInt("0x" + hexOutput.SubString(17, 8));
  //	buffer[3] = StrToInt("0x" + hexOutput.SubString(25, 8));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{

//функции из 4 пункта
 unsigned int F(unsigned int X, unsigned int Y, unsigned int Z);
	unsigned int G(unsigned int X, unsigned int Y, unsigned int Z);
	unsigned int H(unsigned int X, unsigned int Y, unsigned int Z);
	unsigned int I(unsigned int X, unsigned int Y, unsigned int Z);

	// генерация массива белого шума
	unsigned int T[64];
	for (int i = 1; i < 65; i++)
	{
		T[i] = static_cast<unsigned int>(4294967296 * fabs(sin(i)));//формула по условию
		Memo5->Lines->Add(T[i]);
	}

	  UnicodeString message = Memo2->Text; //берем как сообщение текст


	  System::DynamicArray<Byte> bytes = WideBytesOf(message);

 int N = zeroPadding / 8; // кол-во блоков сообщения

 unsigned int X[16]; // массив для блока сообщения

   //обработка сообщения по условию
    for (int i = 0; i < N / 16; i++)
	{
		// копирование блока сообщения номер i в массив X
		for (int k = 0; k < 16; k++)
		{
			int index = i * 16 + k;
			X[k] = bytes[index];
		}

	}

		//инициализация a, b, c, d значениями буффера
unsigned int A = buffer[0];
unsigned int B = buffer[1];
unsigned int C = buffer[2];
unsigned int D = buffer[3];

unsigned int AA = A;
unsigned int BB = B;
unsigned int CC = C;
unsigned int DD = D;

unsigned int s = rand() % 32 + 1; // значение сдвига s


//4 раунда по 4 преобразования в каждом 16 раз
for (int round = 0; round < 4; round++)
{
	for (int i = 0; i < 16; i++)
    {
        unsigned int temp;

		switch (round)
        {
            case 0:
                temp = B + ((A + F(B, C, D) + X[i] + T[i]) << s);
                break;
			case 1:
                temp = B + ((A + G(B, C, D) + X[i] + T[i]) << s);
                break;
            case 2:
                temp = B + ((A + H(B, C, D) + X[i] + T[i]) << s);
				break;
            case 3:
                temp = B + ((A + I(B, C, D) + X[i] + T[i]) << s);
                break;
        }

        A = B;
		B = C;
		C = D;
		D = temp;
	}

	A += AA;
	B += BB;
	C += CC;
	D += DD;
}


//для побайтового вывода a, b, c, d
unsigned char* aBytes = reinterpret_cast<unsigned char*>(&A);
unsigned char* bBytes = reinterpret_cast<unsigned char*>(&B);
unsigned char* cBytes = reinterpret_cast<unsigned char*>(&C);
unsigned char* dBytes = reinterpret_cast<unsigned char*>(&D);

Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
//итоговый выод a, b, c, d
for (int i = sizeof(unsigned int) - 1; i >= 0; i--)
{
	Edit1->Text += IntToHex(aBytes[i], 2);
}

for (int i = sizeof(unsigned int) - 1; i >= 0; i--)
{
	Edit2->Text += IntToHex(bBytes[i], 2);
}

for (int i = sizeof(unsigned int) - 1; i >= 0; i--)
{
	Edit3->Text += IntToHex(cBytes[i], 2);
}

for (int i = sizeof(unsigned int) - 1; i >= 0; i--)
{
	Edit4->Text += IntToHex(dBytes[i], 2);
}


Edit5->Text=Edit1->Text+Edit2->Text+Edit3->Text+Edit4->Text ;
}
//---------------------------------------------------------------------------
