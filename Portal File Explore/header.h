#include<stdio.h>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<conio.h>
#include<iostream>

using namespace std;

long int OffDosHeader = 0;
long int OffFileHeader = 0;
long int OffOptHeader = 0;
long int OffSecHeader = 0;

void CalculateOffset(int);

class dos_header
{
    public:
        IMAGE_DOS_HEADER dosheader;
        int fp;
        dos_header(int f)
        {
            fp = f;
            _lseek(fp, OffDosHeader,0);
            _read(f,&dosheader,sizeof(dosheader));
        }
        void dos_show_header(dosheader);
};
class file_header
{
    public:
        IMAGE_FILE_HEADER fileHeader;
        int fp;
        file_header(int f)
        {
            fp = f;
            _lseek(fp, OffFileHeader,0);
            _read(f,&fileHeader,sizeof(fileHeader));
        }
        void file_show_header(fileHeader);
};
class opt_header
{
    public:
        IMAGE_OPTIONAL_HEADER optheader;
        int fp;
        opt_header(int f)
        {
            fp = f;
            _lseek(fp, OffOptHeader,0);
            _read(f,&optheader,sizeof(optheader));
        }
        void opt_show_header(optheader);
};
class sec_header
{
    public:
        IMAGE_SECTION_HEADER secHeader;
        int NoOfSec;
        int fp;
        sec_header(int f)
        {
            IMAGE_FILE_HEADER fileHeader;
            fp = f;
            _lseek(fp, OffFileHeader,0);
            _read(f,&fileHeader,sizeof(fileHeader));
            NoOfSec = fileHeader.NumberOfSections;

            _lseek(f, OffSecHeader,0);
            _read(f,&secHeader,sizeof(secHeader));

        }
        void sec_show_header(secHeader);
};