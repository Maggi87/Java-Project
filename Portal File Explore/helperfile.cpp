#include"header.h"

void CalculateOffset(int fd)
{
    IMAGE_DOS_HEADER dosheader;
    _read(fd,&dosheader,sizeof(dosheader));

    OffDosHeader = 0;
    OffFileHeader = dosheader.e_lfanew + 4;
    OffOptHeader = OffFileHeader + 0*14;
    OffSecHeader = OffOptHeader+sizeof(IMAGE_OPTIONAL_HEADER);
    _lseek(fd,0,0);
}

 
 void dos_show_header(IMAGE_DOS_HEADER dosheader)
 {
     cout<<endl<<"-------------------------Dos Header Information--------------------------------------"<<endl;
     cout<<endl<<"Magic Number :"                   <<std::hex<<dosheader.e_magic<<endl;
     cout<<endl<<"Bytes on last page of file :"     <<dosheader.e_cblp<<endl;
     cout<<endl<<"page in file :"                   <<dosheader.e_cp<<endl;
     cout<<endl<<"Relocation :"                     <<dosheader.e_crlc<<endl;
     cout<<endl<<"Size of header in paragraphs :"   <<dosheader.e_cparhdr<<endl;
     cout<<endl<<"Minimum extra paragraph needed :" <<dosheader.e_minalloc<<endl;
     cout<<endl<<"Maximun extra paragraph needed :" <<dosheader.e_maxalloc<<endl;
     cout<<endl<<"Initial (relative) ss Value"      <<dosheader.e_ss<<endl;
     cout<<endl<<"Initial SP Value"                 <<dosheader.e_sp<<endl;
     cout<<endl<<"CheckSum : "                      <<dosheader.e_csum<<endl;
     cout<<endl<<"Initial IP Value :"               <<dosheader.e_ip<<endl;
     cout<<endl<<"Initial (Relative) CS Value : "   <<dosheader.e_cs<<endl;
     cout<<endl<<"File address of relocation tablr" <<dosheader.e_lfarlc<<endl;
     cout<<endl<<"Overlay number : "                <<dosheader.e_ovno<<endl;
     cout<<endl<<"OEM identifier : "                <<dosheader.e_oemid<<endl;
     cout<<endl<<"OEM information_oemid specific :" <<dosheader.e_oeminfo<<endl;
     cout<<endl<<"RVA address of PE header :"       <<dosheader.e_lfanew<<endl;
 }

 void file_show_header(IMAGE_FILE_HEADER fileHeader)
 {
     cout<<endl<<"--------------------------File Header Info----------------------------"<<endl;
     cout<<endl<<"Machine : "                      <<fileHeader.Machine<<endl;
     cout<<endl<<"Number Of Section :"             <<fileHeader.NumberOfSections<<endl;
     cout<<endl<<"Time Date Stamp :"               <<fileHeader.TimeDateStamp<<endl;
     cout<<endl<<"Pointer to symbol table :"       <<fileHeader.PointerToSymbolTable<<endl;
     cout<<endl<<"Number of Symbol :"              <<fileHeader.NumberOfSymbols<<endl;
     cout<<endl<<"Size of Optional Header :"       <<fileHeader.SizeOfOptionalHeader<<endl;
     cout<<endl<<"Characterstics : "               <<fileHeader.Characteristics<<endl;
 }

 void opt_show_header(IMAGE_OPTIONAL_HEADER optheader)
 {
     cout<<endl<<"--------------------------Optional Header Info-----------------------------"<<endl;
     cout<<endl<<"Magic :"                              <<optheader.Magic<<endl;
     cout<<endl<<"Size of Code :"                       <<optheader.SizeOfCode<<endl;
     cout<<endl<<"Size of size Of initialed Date :"     <<optheader.SizeOfInitializedData<<endl;
     cout<<endl<<"Size of size of Uniinitialized Date :"<<optheader.SizeOfUninitializedData<<endl;
     cout<<endl<<"Address Of entry Point :"             <<optheader.AddressOfEntryPoint<<endl;
     cout<<endl<<"Base of Code :"                       <<optheader.BaseOfCode<<endl;
     cout<<endl<<"Base of Date :"                       <<optheader.BaseOfData<<endl;
     cout<<endl<<"Image Base :"                         <<optheader.ImageBase<<endl;
     cout<<endl<<"Section Alignment :"                  <<optheader.SectionAlignment<<endl;
     cout<<endl<<"File Alignment :"                     <<optheader.FileAlignment<<endl;
     cout<<endl<<"Major Operating Syetem Version :"     <<optheader.MajorOperatingSystemVersion<<endl;
     cout<<endl<<"Minor Operating Syetem Version :"     <<optheader.MinorOperatingSystemVersion<<endl;
     cout<<endl<<"Major Image Veesion :"                <<optheader.MajorImageVersion<<endl;
     cout<<endl<<"Minor Image Version :"                <<optheader.MinorImageVersion<<endl;
     cout<<endl<<"Major subsystem Version : "           <<optheader.MajorSubsystemVersion<<endl;
     cout<<endl<<"Minor subsystem Version : "           <<optheader.MinorSubsystemVersion<<endl;
     cout<<endl<<"Size of Image :"                      <<optheader.SizeOfImage<<endl;
     cout<<endl<<"Size of Header :"                     <<optheader.SizeOfHeader<<endl;
     cout<<endl<<"Checksum :"                           <<optheader.CheckSum<<endl;

     cout<<endl<<"Subsystem :"                          <<optheader.Subsystem<<endl;
     cout<<endl<<"Dll characterstics"                   <<optheader.DllCharacteristics<<endl;
     cout<<endl<<"Size of Stack Revers :"               <<optheader.SizeOfStackReserve<<endl;
     cout<<endl<<"Size of Stack commit :"               <<optheader.SizeOfStackCommit<<endl;
     cout<<endl<<"Size of Heap Reserve :"               <<optheader.SizeOfHeapReserve<<endl;
     cout<<endl<<"Size of Heap Commit :"                <<optheader.SizeOfHeapCommit<<endl;
     cout<<endl<<"Loader Flags :"                       <<optheader.LoaderFlags<<endl;
     cout<<endl<<"Number Of RVA and Size :"             <<optheader.NumberOfRvaAndSizes<<endl;
 }

 void sec_show_header(IMAGE_SECTION_HEADER secHeader)
 {
     cout<<endl<<"--------------SECTION HEADER INFO--------------"<<endl;
     while(NoOfSec!=0)
     {
         cout<<endl<<"Name :"<<secHeader.Name<<endl;
         cout<<endl<<"Virtual Address :"<<secHeader.VirtualAddress<<endl;
         cout<<endl<<"Size of Raw Data :"<<secHeader.SizeOfRawData<<endl;
         cout<<endl<<"Pointer To Raw Data :"<<secHeader.PointerToRawData<<endl;
         cout<<endl<<"Pointer To Relocation :"<<secHeader.PointerToRelocations<<endl;
         cout<<endl<<"Pointer To Line Number :"<<secHeader.PointerToLinenumbers<<endl;
         cout<<endl<<"Number of Relocations :"<<secHeader.NumberOfRelocations<<endl;
         cout<<endl<<"Number of Line Number :"<<secHeader.NumberOdLinenumbers<<endl;
         cout<<endl<<"Characteristics :"<<secHeader.Characteristics<<endl;
         NoOfSec--;
         cout<<endl<<"--------------------------------------------------------"<<endl;
         _read(fp,&secHeader,sizeof(secHeader));
     }
 }

  