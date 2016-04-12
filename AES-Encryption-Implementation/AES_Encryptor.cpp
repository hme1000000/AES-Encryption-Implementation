#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <time.h>
#include <sstream>
using namespace std;
#include <cstring>

unsigned char s_box[256] = 
 {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16

 };

unsigned char s_box_after_mul[256] =
	{
		0xc6, 0xf8, 0xee, 0xf6, 0xff, 0xd6, 0xde, 0x91, 0x60, 0x2, 0xce, 0x56, 0xe7, 0xb5, 0x4d, 0xec,
		0x8f, 0x1f, 0x89, 0xfa, 0xef, 0xb2, 0x8e, 0xfb, 0x41, 0xb3, 0x5f, 0x45, 0x23, 0x53, 0xe4, 0x9b,
		0x75, 0xe1, 0x3d, 0x4c, 0x6c, 0x7e, 0xf5, 0x83, 0x68, 0x51, 0xd1, 0xf9, 0xe2, 0xab, 0x62, 0x2a,
		0x8, 0x95, 0x46, 0x9d, 0x30, 0x37, 0xa, 0x2f, 0xe, 0x24, 0x1b, 0xdf, 0xcd, 0x4e, 0x7f, 0xea,
		0x12, 0x1d, 0x58, 0x34, 0x36, 0xdc, 0xb4, 0x5b, 0xa4, 0x76, 0xb7, 0x7d, 0x52, 0xdd, 0x5e, 0x13,
		0xa6, 0xb9, 0x0, 0xc1, 0x40, 0xe3, 0x79, 0xb6, 0xd4, 0x8d, 0x67, 0x72, 0x94, 0x98, 0xb0, 0x85,
		0xbb, 0xc5, 0x4f, 0xed, 0x86, 0x9a, 0x66, 0x11, 0x8a, 0xe9, 0x4, 0xfe, 0xa0, 0x78, 0x25, 0x4b,
		0xa2, 0x5d, 0x80, 0x5, 0x3f, 0x21, 0x70, 0xf1, 0x63, 0x77, 0xaf, 0x42, 0x20, 0xe5, 0xfd, 0xbf,
		0x81, 0x18, 0x26, 0xc3, 0xbe, 0x35, 0x88, 0x2e, 0x93, 0x55, 0xfc, 0x7a, 0xc8, 0xba, 0x32, 0xe6,
		0xc0, 0x19, 0x9e, 0xa3, 0x44, 0x54, 0x3b, 0xb, 0x8c, 0xc7, 0x6b, 0x28, 0xa7, 0xbc, 0x16, 0xad,
		0xdb, 0x64, 0x74, 0x14, 0x92, 0xc, 0x48, 0xb8, 0x9f, 0xbd, 0x43, 0xc4, 0x39, 0x31, 0xd3, 0xf2,
		0xd5, 0x8b, 0x6e, 0xda, 0x1, 0xb1, 0x9c, 0x49, 0xd8, 0xac, 0xf3, 0xcf, 0xca, 0xf4, 0x47, 0x10,
		0x6f, 0xf0, 0x4a, 0x5c, 0x38, 0x57, 0x73, 0x97, 0xcb, 0xa1, 0xe8, 0x3e, 0x96, 0x61, 0xd, 0xf,
		0xe0, 0x7c, 0x71, 0xcc, 0x90, 0x6, 0xf7, 0x1c, 0xc2, 0x6a, 0xae, 0x69, 0x17, 0x99, 0x3a, 0x27,
		0xd9, 0xeb, 0x2b, 0x22, 0xd2, 0xa9, 0x7, 0x33, 0x2d, 0x3c, 0x15, 0xc9, 0x87, 0xaa, 0x50, 0xa5,
		0x3, 0x59, 0x9, 0x1a, 0x65, 0xd7, 0x84, 0xd0, 0x82, 0x29, 0x5a, 0x1e, 0x7b, 0xa8, 0x6d, 0x2c,
	};

unsigned char Rcon[11] = {0x0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};

//////////////////////////////////////////////////////////////////////////////
inline void expand_key(unsigned int key[4],unsigned int expanded_key[44])
{
	for(int i=0;i<4;i++)
	{
		expanded_key[i] = key[i];
	}
	for(int i=4;i<44;i++)
	{
		unsigned int temp = expanded_key[i-1];
		if(i%4 == 0)
		{
			temp = (temp<<8)|(temp>>24);
			temp = (s_box[temp>>24]<<24|s_box[(temp>>16)&0xFF]<<16|s_box[(temp>>8)&0xFF]<<8|s_box[(temp)&0xFF])^(Rcon[i>>2]<<24);
		}
		expanded_key[i] = expanded_key[i-4]^temp;
	}
}
////////////////////////////////////////////////////////////////////////////
void encrypt(unsigned int input[4],unsigned int key[44],unsigned int output[4])
{
	for(int i=0;i<4;i++)
	{
		output[i] = input[i]^key[i];
	}		
	unsigned int shift_out[4][4];
	for(int k=1;k<10;k++)
	{		
		for(int i=0;i<4;i++)
		{
			shift_out[0][i] = output[i]>>24;
			shift_out[1][i] = (output[(i+1)&0x3]>>16)&0xFF;
			shift_out[2][i] = (output[(i+2)&0x3]>>8)&0xFF;
			shift_out[3][i] = output[(i+3)&0x3]&0xFF;
		}
		for(int i=0;i<4;i++)
		{
			output[i] = ((s_box_after_mul[shift_out[0][i]])^
				(s_box_after_mul[shift_out[1][i]])^(s_box[shift_out[1][i]])^(s_box[shift_out[2][i]])^(s_box[shift_out[3][i]]))<<24;

			output[i] = output[i]|(((s_box_after_mul[shift_out[1][i]])^
				(s_box_after_mul[shift_out[2][i]])^(s_box[shift_out[2][i]])^(s_box[shift_out[3][i]])^(s_box[shift_out[0][i]]))<<16);

			output[i] = output[i]|(((s_box_after_mul[shift_out[2][i]])^
				(s_box_after_mul[shift_out[3][i]])^(s_box[shift_out[3][i]])^(s_box[shift_out[0][i]])^(s_box[shift_out[1][i]]))<<8);

			output[i] = output[i]|((s_box_after_mul[shift_out[3][i]])^
				(s_box_after_mul[shift_out[0][i]])^(s_box[shift_out[0][i]])^(s_box[shift_out[1][i]])^(s_box[shift_out[2][i]]));
			output[i] = output[i]^key[i+(k*4)];
		}
	}
	for(int i=0;i<4;i++)
		{
			shift_out[0][i] = output[i]>>24;			
			shift_out[1][i] = (output[(i+1)&0x3]>>16)&0xFF;
			shift_out[2][i] = (output[(i+2)&0x3]>>8)&0xFF;
			shift_out[3][i] = output[(i+3)&0x3]>>0&0xFF;
		}
	for(int i=0;i<4;i++)
	{
		output[i] = s_box[shift_out[0][i]]<<24;
		output[i] = output[i]|((s_box[shift_out[1][i]])<<16);
		output[i] = output[i]|((s_box[shift_out[2][i]])<<8);
		output[i] = output[i]|(s_box[shift_out[3][i]]);
		output[i] = output[i]^key[i+40];
	}
}
////////////////////////////////////////////////////////////////////////


int main()
{	
	//freopen("put3.txt","r",stdin);
	//freopen("AES_Output.txt","w",stdout);	
	int n;	
	cin>>n;
	double t1 = clock();
	for(int i=0;i<n;i++)
	{
		string s_input;
		string s_key;
		int m;
		unsigned int input[4];
		unsigned int key[4];
		cin>>s_input;
		char c_input[33];
		strcpy(c_input,s_input.c_str());
		sscanf(c_input,"%8X%8X%8X%8X",&input[0],&input[1],&input[2],&input[3]);
		cin>>s_key;
		char c_key[33];
		strcpy(c_key,s_key.c_str());
		sscanf(c_key,"%8X%8X%8X%8X",&key[0],&key[1],&key[2],&key[3]);
		cin>>m;	
		unsigned int input_key[44];
		expand_key(key,input_key);
		unsigned int output[4];
		encrypt(input,input_key,output);
		for(int i=1;i<m;i++)
		{			
			encrypt(output,input_key,output);			
		}
		for(int i=0;i<4;i++)
			{
				//cout<<hex<<output[i];
				printf("%08X",output[i]);
				//cout << setfill('0')<< setw(8)<< hex  <<output[i];
			}
			cout<<endl;
	}
	double t2 = clock();
	cout<<"elapse: "<<(((double)(t2 - t1)) * 1000) / CLOCKS_PER_SEC<<endl<<endl;
	return 0;
}


