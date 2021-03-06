#include <iostream>
#include <vector>
#include <string>
using namespace std; 

//Implement the encryption/decryption algorithm of the Advanced Encryption System (AES) for 16 byte key(128 bit). Assume that the plaintext input message is always of length 128 bits.

vector<vector<int>> byteSub(vector<vector<int>>sub){
     int s[256] =  
 {0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
 ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
 ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
 ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
 ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
 ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
 ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
 ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
 ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
 ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
 ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
 ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
 ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
 ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
 ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
 ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16};
//s-box

for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
        int temp; 
        temp=sub[i][j]; 
        int lBits= (temp>>4); //get last 4 bits
        int rBits = (temp & 0b1111);//get first 4 bits
        int sIndex;//uses correct index value i.e. 95=row 9 col 5 (note: 95 is in hex)
        sIndex=(lBits*16)+rBits;
        sub[i][j]=s[sIndex];
        
    }
}
    return sub; 
}
vector<vector<int>> mixColumns(vector<vector<int>> state){
    vector<vector<int>>mixed; 
    mixed.resize(4); 
     for(int i=0; i<4; i++){ 
        mixed[i].resize(4); 
     }
    unsigned char mul_2[] =
{
    0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
    0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
    0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
    0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
    0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
    0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
    0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
    0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
    0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
    0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
    0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
    0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
    0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
    0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
    0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
    0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};


unsigned char mul_3[] = 
{ 
    0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
    0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
    0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
    0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
    0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
    0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
    0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
    0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
    0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
    0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
    0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
    0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
    0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
    0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
    0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
    0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
}; //lookup tables for mixed columns multipulcation (galois field 2^8)
    int mul2_result;
    int mul3_result;  
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==0){
                mul2_result=mul_2[state[i][j]]; 
                mul3_result=mul_3[state[i+1][j]];
                mixed[0][j]=mul2_result^mul3_result^state[2][j]^state[3][j];
           
           }
            if(i==1){
                mul2_result=mul_2[state[i][j]]; 
                mul3_result=mul_3[state[i+1][j]];
                mixed[1][j]=state[0][j]^mul2_result^mul3_result^state[3][j];
                 
            }
            if(i==2){
                mul2_result=mul_2[state[i][j]]; 
                mul3_result=mul_3[state[i+1][j]];
                mixed[2][j]=state[0][j]^state[1][j]^mul2_result^mul3_result;
                 
            }
             if(i==3){
                mul2_result=mul_2[state[i][j]]; 
                mul3_result=mul_3[state[i-i][j]];
                mixed[3][j]=mul2_result^state[1][j]^state[2][j]^mul3_result;
                 
            }
           
           
        }
    }
    return mixed; 

}

vector<vector<int>> shiftRow(vector<vector<int>>message){
    vector<vector<int>>shifted; 
    shifted.resize(4); 
     for(int i=0; i<4; i++){ 
        shifted[i].resize(4); 
     }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==1){
            //shift to the left by 1 byte so [0][1][2][3]->[1][2][3][0]
                if(j!=0){
                    shifted[i][j-1]=message[i][j]; 
                }
                else{
                    shifted[i][j+3]=message[i][j]; 
                }
                
            }
            else if(i==2){
            //shift to the left by 2 bytes so [0][1][2][3]->[2][3][0][1]
                if(j<2){
                    shifted[i][j+2]=message[i][j];  
                }
                else{
                    shifted[i][j-2]=message[i][j]; 
                }
            }
            else if(i==3){
            //shift to the left by 3 bytes(or same as shift to right 1 byte) so [0][1][2][3]->[3][0][1][2]
                if(j==3){
                    shifted[i][j-3]=message[i][j];  
                }
                else{
                    shifted[i][j+1]=message[i][j]; 
                }
            }
            else{
                 shifted[i][j]=message[i][j]; 
            }
        }
    }
    return shifted; 
}
vector<vector<int>> addRoundKey(vector<vector<int>>message, vector<vector<int>>key, int k){
    vector<vector<int>>state; 
    state.resize(4); 
    for(int i=0; i<4; i++){ 
     state[i].resize(4); 
    }
    int l;
    l=k*4; 
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
               state[i][j]=message[i][j]^key[l][j];
        }
        l++; 
     } 
    return state; 
}

void populateKeyMatrix(vector<vector<int>>&mass, vector<vector<int>> key, int l){//pass vector by reference
    vector<vector<int>> temp; 
    for(int i=l; i<l+44; i++){
        mass.push_back(vector<int>(4));
        temp.push_back(vector<int>(4));
    }
     int x=(l*4); 
    for(int i=x; i<x+4; i++){ 
        for(int j=0; j<4; j++){
            temp[i][j]=key[i][j];
        }
    }
    for(int i=x; i<x+4; i++){ 
        for(int j=0; j<4; j++){
            mass[i][j]=temp[j+x][i-x];
            //must make indexes use x because key index 0 is actually x=l*4. [8][0]=[x][0] so [0][8]=[0][8-8] which basically makes it zero index
        }
    }

}
void populateMatrix(vector<vector<int>>&mass, unsigned char normal[]){//pass vector by reference
    int k=0; 
     mass.resize(4); 
     for(int i=0; i<4; i++){ 
        mass[i].resize(4); 
     }
    for(int i=0; i<4; i++){ 
        for(int j=0; j<4; j++){
            mass[i][j]=int(normal[k]);
            k++; 
        }
    }

}
void populateInitialMatrix(vector<vector<int>>&mass, string normal){//pass vector by reference
    int k=0; 
     mass.resize(4); 
     for(int i=0; i<4; i++){ 
        mass[i].resize(4); 
     }
    for(int i=0; i<4; i++){ 
        for(int j=0; j<4; j++){
            mass[j][i]=int(normal[k]);
            k++; 
        }
    }

}
void populateKeyMatrix(vector<vector<int>>&mass, unsigned char normal[]){//pass vector by reference
    int k=0; 
     mass.resize(4); 
     for(int i=0; i<4; i++){ 
        mass[i].resize(4); 
     }
    for(int i=0; i<4; i++){ 
        for(int j=0; j<4; j++){
            mass[j][i]=int(normal[k]);
            k++; 
        }
    }

}


vector<vector<int>> SubWord(vector<vector<int>>sub, int k){
     int s[256] =  
 {0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
 ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
 ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
 ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
 ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
 ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
 ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
 ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
 ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
 ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
 ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
 ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
 ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
 ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
 ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
 ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16};
//s-box

for(int i=k; i<k+1; i++){
    for(int j=0; j<4; j++){
        int temp; 
        temp=sub[k][j]; 
        int lBits= (temp>>4); //get last 4 bits
        int rBits = (temp & 0b1111);
        //get first 4 bits 0000 1111
        //and operator     xxxx xxxx= (0 and any value=zero). (1 and 1=1) while (1 and 0=zero) but that value won't count anyways
        int sIndex;//uses correct index value i.e. 95=row 9 col 5 (note: 95 is in hex)
        sIndex=(lBits*16)+rBits;
        sub[k][j]=s[sIndex];
        
    }
}
    return sub; 
}
vector<vector<int>> rotWord(vector<vector<int>> rotate, int k){
    int temp=rotate[k][0];
    for(int j=0; j<3; j++){
        rotate[k][j]=rotate[k][j+1];
    }
     rotate[k][3]=temp; 
   
    return rotate; 
}
void keyExpansion (vector<vector<int>> key, vector<vector<int>>&word){
    int please;
    vector<vector<int>> temp; 
    unsigned int rCon[]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};//round constant
    for(int i=0; i<44; i++){
        word.push_back(vector<int>(4));
        temp.push_back(vector<int>(4));
    }
     
//iterates through first 4 words but using 2d array so each row consists of one word. one word=4 ints
    for (int i = 0; i < 4; i++) { 
        for(int j=0; j<4; j++){
            word[i][j]=key[i][j];
        }       
    }
 
    for (int i = 4; i < 44; i++){
        for(int j=0; j<4; j++){
            temp[i][j]=word[i-1][j];
            if(i%4==0 && j==3){
                temp=rotWord(temp, i);
                temp=SubWord(temp, i);
                temp[i][0]=temp[i][0]^rCon[(i/4)-1]; 

                please=word[i-4][j-3]^temp[i][j-3];
                word[i][j-3]=please; //first index value

                please=word[i-4][j-2]^temp[i][j-2];
                word[i][j-2]=please;//2nd index value

                please=word[i-4][j-1]^temp[i][j-1];
                word[i][j-1]=please; //3rd index value

                please=word[i-4][j]^temp[i][j];
                word[i][j]=please;//4th index value
            }
            if(i%4!=0){
                please=word[i-4][j]^temp[i][j];
                word[i][j]=please; 

            }
         
        }   
    }
    
}
void printMessage(vector<vector<int>> messageBite){
     for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //if you want to see it in hex, uncomment the next line
            //cout<<hex<<messageBite[i][j]<<" "; 
            cout<<(char)messageBite[i][j]<<" "; 
            if(j==3){
                cout<<endl; 
            }
        }
    } 
    // cout<<endl;
}
vector<vector<int>> inverseShiftRow(vector<vector<int>>message){
    vector<vector<int>>shifted; 
    shifted.resize(4); 
     for(int i=0; i<4; i++){ 
        shifted[i].resize(4); 
     }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==1){
            //shift to the right by 1 byte so [0][1][2][3]->[3][0][1][2]
                if(j!=3){
                    shifted[i][j+1]=message[i][j]; 
                }
                else{
                    shifted[i][j-3]=message[i][j]; 
                }
                
            }
            else if(i==2){
            //shift to the right by 2 bytes so [0][1][2][3]->[2][3][0][1]
                if(j<2){
                    shifted[i][j+2]=message[i][j];  
                }
                else{
                    shifted[i][j-2]=message[i][j]; 
                }
            }
            else if(i==3){
            //shift to the right by 3 bytes(or same as shift to left 1 byte) so [0][1][2][3]->[1][2][3][0]
                if(j==0){
                    shifted[i][j+3]=message[i][j];  
                }
                else{
                    shifted[i][j-1]=message[i][j]; 
                }
            }
            else{
                 shifted[i][j]=message[i][j]; 
            }
        }
    }
    return shifted; 
}
vector<vector<int>> inverseSubBytes(vector<vector<int>>sub){
     int s[256] =  
{   0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb, 
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb, 
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e, 
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25, 
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92, 
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84, 
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06, 
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b, 
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73, 
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e, 
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b, 
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4, 
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f, 
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef, 
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61, 
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};
//inverse s-box

for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
        int temp; 
        temp=sub[i][j]; 
        int lBits= (temp>>4); //get last 4 bits
        int rBits = (temp & 0b1111);//get first 4 bits
        int sIndex;//uses correct index value i.e. 95=row 9 col 5 (note: 95 is in hex)
        sIndex=(lBits*16)+rBits;
        sub[i][j]=s[sIndex];
        
    }
}
    return sub; 
}
vector<vector<int>> inverseMixColumns(vector<vector<int>> state){
    vector<vector<int>>mixed; 
    mixed.resize(4); 
     for(int i=0; i<4; i++){ 
        mixed[i].resize(4); 
     }
unsigned char mul_9[] = {
0x00,0x09,0x12,0x1b,0x24,0x2d,0x36,0x3f,0x48,0x41,0x5a,0x53,0x6c,0x65,0x7e,0x77,
0x90,0x99,0x82,0x8b,0xb4,0xbd,0xa6,0xaf,0xd8,0xd1,0xca,0xc3,0xfc,0xf5,0xee,0xe7,
0x3b,0x32,0x29,0x20,0x1f,0x16,0x0d,0x04,0x73,0x7a,0x61,0x68,0x57,0x5e,0x45,0x4c,
0xab,0xa2,0xb9,0xb0,0x8f,0x86,0x9d,0x94,0xe3,0xea,0xf1,0xf8,0xc7,0xce,0xd5,0xdc,
0x76,0x7f,0x64,0x6d,0x52,0x5b,0x40,0x49,0x3e,0x37,0x2c,0x25,0x1a,0x13,0x08,0x01,
0xe6,0xef,0xf4,0xfd,0xc2,0xcb,0xd0,0xd9,0xae,0xa7,0xbc,0xb5,0x8a,0x83,0x98,0x91,
0x4d,0x44,0x5f,0x56,0x69,0x60,0x7b,0x72,0x05,0x0c,0x17,0x1e,0x21,0x28,0x33,0x3a,
0xdd,0xd4,0xcf,0xc6,0xf9,0xf0,0xeb,0xe2,0x95,0x9c,0x87,0x8e,0xb1,0xb8,0xa3,0xaa,	
0xec,0xe5,0xfe,0xf7,0xc8,0xc1,0xda,0xd3,0xa4,0xad,0xb6,0xbf,0x80,0x89,0x92,0x9b,	
0x7c,0x75,0x6e,0x67,0x58,0x51,0x4a,0x43,0x34,0x3d,0x26,0x2f,0x10,0x19,0x02,0x0b,
0xd7,0xde,0xc5,0xcc,0xf3,0xfa,0xe1,0xe8,0x9f,0x96,0x8d,0x84,0xbb,0xb2,0xa9,0xa0,
0x47,0x4e,0x55,0x5c,0x63,0x6a,0x71,0x78,0x0f,0x06,0x1d,0x14,0x2b,0x22,0x39,0x30,
0x9a,0x93,0x88,0x81,0xbe,0xb7,0xac,0xa5,0xd2,0xdb,0xc0,0xc9,0xf6,0xff,0xe4,0xed,
0x0a,0x03,0x18,0x11,0x2e,0x27,0x3c,0x35,0x42,0x4b,0x50,0x59,0x66,0x6f,0x74,0x7d,	
0xa1,0xa8,0xb3,0xba,0x85,0x8c,0x97,0x9e,0xe9,0xe0,0xfb,0xf2,0xcd,0xc4,0xdf,0xd6,
0x31,0x38,0x23,0x2a,0x15,0x1c,0x07,0x0e,0x79,0x70,0x6b,0x62,0x5d,0x54,0x4f,0x46};

unsigned char mul_11[] = {
0x00,0x0b,0x16,0x1d,0x2c,0x27,0x3a,0x31,0x58,0x53,0x4e,0x45,0x74,0x7f,0x62,0x69,
0xb0,0xbb,0xa6,0xad,0x9c,0x97,0x8a,0x81,0xe8,0xe3,0xfe,0xf5,0xc4,0xcf,0xd2,0xd9,
0x7b,0x70,0x6d,0x66,0x57,0x5c,0x41,0x4a,0x23,0x28,0x35,0x3e,0x0f,0x04,0x19,0x12,
0xcb,0xc0,0xdd,0xd6,0xe7,0xec,0xf1,0xfa,0x93,0x98,0x85,0x8e,0xbf,0xb4,0xa9,0xa2,
0xf6,0xfd,0xe0,0xeb,0xda,0xd1,0xcc,0xc7,0xae,0xa5,0xb8,0xb3,0x82,0x89,0x94,0x9f,
0x46,0x4d,0x50,0x5b,0x6a,0x61,0x7c,0x77,0x1e,0x15,0x08,0x03,0x32,0x39,0x24,0x2f,
0x8d,0x86,0x9b,0x90,0xa1,0xaa,0xb7,0xbc,0xd5,0xde,0xc3,0xc8,0xf9,0xf2,0xef,0xe4,
0x3d,0x36,0x2b,0x20,0x11,0x1a,0x07,0x0c,0x65,0x6e,0x73,0x78,0x49,0x42,0x5f,0x54,
0xf7,0xfc,0xe1,0xea,0xdb,0xd0,0xcd,0xc6,0xaf,0xa4,0xb9,0xb2,0x83,0x88,0x95,0x9e,
0x47,0x4c,0x51,0x5a,0x6b,0x60,0x7d,0x76,0x1f,0x14,0x09,0x02,0x33,0x38,0x25,0x2e,
0x8c,0x87,0x9a,0x91,0xa0,0xab,0xb6,0xbd,0xd4,0xdf,0xc2,0xc9,0xf8,0xf3,0xee,0xe5,
0x3c,0x37,0x2a,0x21,0x10,0x1b,0x06,0x0d,0x64,0x6f,0x72,0x79,0x48,0x43,0x5e,0x55,
0x01,0x0a,0x17,0x1c,0x2d,0x26,0x3b,0x30,0x59,0x52,0x4f,0x44,0x75,0x7e,0x63,0x68,
0xb1,0xba,0xa7,0xac,0x9d,0x96,0x8b,0x80,0xe9,0xe2,0xff,0xf4,0xc5,0xce,0xd3,0xd8,
0x7a,0x71,0x6c,0x67,0x56,0x5d,0x40,0x4b,0x22,0x29,0x34,0x3f,0x0e,0x05,0x18,0x13,
0xca,0xc1,0xdc,0xd7,0xe6,0xed,0xf0,0xfb,0x92,0x99,0x84,0x8f,0xbe,0xb5,0xa8,0xa3};

unsigned char mul_13[] = {
0x00,0x0d,0x1a,0x17,0x34,0x39,0x2e,0x23,0x68,0x65,0x72,0x7f,0x5c,0x51,0x46,0x4b,
0xd0,0xdd,0xca,0xc7,0xe4,0xe9,0xfe,0xf3,0xb8,0xb5,0xa2,0xaf,0x8c,0x81,0x96,0x9b,
0xbb,0xb6,0xa1,0xac,0x8f,0x82,0x95,0x98,0xd3,0xde,0xc9,0xc4,0xe7,0xea,0xfd,0xf0,
0x6b,0x66,0x71,0x7c,0x5f,0x52,0x45,0x48,0x03,0x0e,0x19,0x14,0x37,0x3a,0x2d,0x20,
0x6d,0x60,0x77,0x7a,0x59,0x54,0x43,0x4e,0x05,0x08,0x1f,0x12,0x31,0x3c,0x2b,0x26,
0xbd,0xb0,0xa7,0xaa,0x89,0x84,0x93,0x9e,0xd5,0xd8,0xcf,0xc2,0xe1,0xec,0xfb,0xf6,
0xd6,0xdb,0xcc,0xc1,0xe2,0xef,0xf8,0xf5,0xbe,0xb3,0xa4,0xa9,0x8a,0x87,0x90,0x9d,
0x06,0x0b,0x1c,0x11,0x32,0x3f,0x28,0x25,0x6e,0x63,0x74,0x79,0x5a,0x57,0x40,0x4d,
0xda,0xd7,0xc0,0xcd,0xee,0xe3,0xf4,0xf9,0xb2,0xbf,0xa8,0xa5,0x86,0x8b,0x9c,0x91,
0x0a,0x07,0x10,0x1d,0x3e,0x33,0x24,0x29,0x62,0x6f,0x78,0x75,0x56,0x5b,0x4c,0x41,
0x61,0x6c,0x7b,0x76,0x55,0x58,0x4f,0x42,0x09,0x04,0x13,0x1e,0x3d,0x30,0x27,0x2a,
0xb1,0xbc,0xab,0xa6,0x85,0x88,0x9f,0x92,0xd9,0xd4,0xc3,0xce,0xed,0xe0,0xf7,0xfa,
0xb7,0xba,0xad,0xa0,0x83,0x8e,0x99,0x94,0xdf,0xd2,0xc5,0xc8,0xeb,0xe6,0xf1,0xfc,
0x67,0x6a,0x7d,0x70,0x53,0x5e,0x49,0x44,0x0f,0x02,0x15,0x18,0x3b,0x36,0x21,0x2c,
0x0c,0x01,0x16,0x1b,0x38,0x35,0x22,0x2f,0x64,0x69,0x7e,0x73,0x50,0x5d,0x4a,0x47,
0xdc,0xd1,0xc6,0xcb,0xe8,0xe5,0xf2,0xff,0xb4,0xb9,0xae,0xa3,0x80,0x8d,0x9a,0x97};

unsigned char mul_14[] = {
0x00,0x0e,0x1c,0x12,0x38,0x36,0x24,0x2a,0x70,0x7e,0x6c,0x62,0x48,0x46,0x54,0x5a,
0xe0,0xee,0xfc,0xf2,0xd8,0xd6,0xc4,0xca,0x90,0x9e,0x8c,0x82,0xa8,0xa6,0xb4,0xba,
0xdb,0xd5,0xc7,0xc9,0xe3,0xed,0xff,0xf1,0xab,0xa5,0xb7,0xb9,0x93,0x9d,0x8f,0x81,
0x3b,0x35,0x27,0x29,0x03,0x0d,0x1f,0x11,0x4b,0x45,0x57,0x59,0x73,0x7d,0x6f,0x61,
0xad,0xa3,0xb1,0xbf,0x95,0x9b,0x89,0x87,0xdd,0xd3,0xc1,0xcf,0xe5,0xeb,0xf9,0xf7,
0x4d,0x43,0x51,0x5f,0x75,0x7b,0x69,0x67,0x3d,0x33,0x21,0x2f,0x05,0x0b,0x19,0x17,
0x76,0x78,0x6a,0x64,0x4e,0x40,0x52,0x5c,0x06,0x08,0x1a,0x14,0x3e,0x30,0x22,0x2c,
0x96,0x98,0x8a,0x84,0xae,0xa0,0xb2,0xbc,0xe6,0xe8,0xfa,0xf4,0xde,0xd0,0xc2,0xcc,
0x41,0x4f,0x5d,0x53,0x79,0x77,0x65,0x6b,0x31,0x3f,0x2d,0x23,0x09,0x07,0x15,0x1b,
0xa1,0xaf,0xbd,0xb3,0x99,0x97,0x85,0x8b,0xd1,0xdf,0xcd,0xc3,0xe9,0xe7,0xf5,0xfb,
0x9a,0x94,0x86,0x88,0xa2,0xac,0xbe,0xb0,0xea,0xe4,0xf6,0xf8,0xd2,0xdc,0xce,0xc0,
0x7a,0x74,0x66,0x68,0x42,0x4c,0x5e,0x50,0x0a,0x04,0x16,0x18,0x32,0x3c,0x2e,0x20,
0xec,0xe2,0xf0,0xfe,0xd4,0xda,0xc8,0xc6,0x9c,0x92,0x80,0x8e,0xa4,0xaa,0xb8,0xb6,
0x0c,0x02,0x10,0x1e,0x34,0x3a,0x28,0x26,0x7c,0x72,0x60,0x6e,0x44,0x4a,0x58,0x56,
0x37,0x39,0x2b,0x25,0x0f,0x01,0x13,0x1d,0x47,0x49,0x5b,0x55,0x7f,0x71,0x63,0x6d,
0xd7,0xd9,0xcb,0xc5,0xef,0xe1,0xf3,0xfd,0xa7,0xa9,0xbb,0xb5,0x9f,0x91,0x83,0x8d};

//lookup tables for mixed columns multipulcation (galois field 2^8)

    int mul9_result;
    int mul11_result;  
    int mul13_result;
    int mul14_result; 
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //s(0,j)=14*s(0,j)^11*s(1,j)^13*s(2,j)^9*s(3,j)
            if(i==0){
                mul14_result=mul_14[state[i][j]]; 
                mul11_result=mul_11[state[i+1][j]];
                mul13_result=mul_13[state[i+2][j]]; 
                mul9_result=mul_9[state[i+3][j]];
                mixed[0][j]=mul14_result^mul11_result^mul13_result^mul9_result;
           
           }
           //s(1,j)=9*s(0,j)^14*s(1,j)^11*s(2,j)^13*s(3,j)
            if(i==1){
                mul9_result=mul_9[state[i-1][j]]; 
                mul14_result=mul_14[state[i][j]];
                mul11_result=mul_11[state[i+1][j]]; 
                mul13_result=mul_13[state[i+2][j]];
                mixed[1][j]=mul9_result^mul14_result^mul11_result^mul13_result;
                 
            }
            //s(2,j)=13*s(0,j)^9*s(1,j)^14*s(2,j)^11*s(3,j)
            if(i==2){
                mul13_result=mul_13[state[i-2][j]]; 
                mul9_result=mul_9[state[i-1][j]];
                mul14_result=mul_14[state[i][j]]; 
                mul11_result=mul_11[state[i+1][j]];
                mixed[2][j]=mul13_result^mul9_result^mul14_result^mul11_result;
                 
            }
            //s(3,j)=11*s(0,j)^13*s(1,j)^9*s(2,j)^14*s(3,j)
             if(i==3){
                mul11_result=mul_11[state[i-3][j]]; 
                mul13_result=mul_13[state[i-2][j]];
                mul9_result=mul_9[state[i-1][j]]; 
                mul14_result=mul_14[state[i][j]];
                mixed[3][j]=mul11_result^mul13_result^mul9_result^mul14_result;
                 
            }
           
           
        }
    }
    return mixed; 

}
void decryption(vector<vector<int>> messageBite, vector<vector<int>> keyBite, vector<vector<int>> temp){
    populateKeyMatrix(keyBite, temp, 10);
    messageBite=addRoundKey(messageBite, keyBite, 10);
    messageBite=inverseShiftRow(messageBite); 
    messageBite=inverseSubBytes(messageBite); 
    for(int i=10; i>1; i--){
        populateKeyMatrix(keyBite, temp, i-1);//populates bitekey with the correctly expanded matrix with it transposed
        messageBite=addRoundKey(messageBite, keyBite, i-1);//adds roundkey each time
        messageBite=inverseMixColumns(messageBite);  
        messageBite=inverseShiftRow(messageBite);
        messageBite=inverseSubBytes(messageBite);
        
    }
    populateKeyMatrix(keyBite, temp, 0);//populates bitekey with the correctly expanded matrix with it transposed
    messageBite=addRoundKey(messageBite, keyBite, 0);//adds roundkey each time
    printMessage(messageBite);
}

void printRounds(vector<vector<int>> messageBite, vector<vector<int>> keyBite, vector<vector<int>> temp){
      for(int i=0; i<9; i++){//i:0-9
        messageBite=byteSub(messageBite);
        messageBite=shiftRow(messageBite); 
        messageBite=mixColumns(messageBite);
        populateKeyMatrix(keyBite, temp, i+1);//populates bitekey with the correctly expanded matrix with it transposed
        messageBite=addRoundKey(messageBite, keyBite, i+1);//adds roundkey each time
        //if you want to see each round then uncomment next line
        //printMessage(messageBite); 
    }
    messageBite=byteSub(messageBite);
    messageBite=shiftRow(messageBite); 
    populateKeyMatrix(keyBite, temp, 10);
    messageBite=addRoundKey(messageBite, keyBite, 10);
    cout<<"Encryption time"<<endl; 
    printMessage(messageBite);
    //decrypt it
    cout<<"Decryption time:"<<endl; 
    decryption(messageBite, keyBite, temp); 

}

int main(){
    //unsigned char message[]={0x00, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd,0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};// one bit difference
    //unsigned char message[]={0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
    unsigned char key[]= {0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98};
    string message;
    cout<<"Enter message to be encrypted: ";
    getline(cin, message);
    vector<vector<int>> bite; 
    vector<vector<int>> biteKey;
    vector<vector<int>> temp;  
    populateInitialMatrix(bite, message);//populate initial message into 2d vector
    printMessage(bite);//print original 16 char message
    populateMatrix(biteKey, key);//populate key into 2d vector
    keyExpansion(biteKey, temp);//expands original key to now be 11 keys
    populateKeyMatrix(biteKey, key);//makes key matrix col x row instead of row x col (transposed)
    bite=addRoundKey(bite, biteKey, 0);
    //printMessage(bite); //print messsage after first add round key
    printRounds(bite, biteKey, temp);//print encrypted message and decrypted message
    
    return 0; 
}
