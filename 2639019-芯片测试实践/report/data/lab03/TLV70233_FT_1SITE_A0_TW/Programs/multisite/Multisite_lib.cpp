





#define MULTISITE_REV "V5_2_0"



#ifndef Multisite_lib_cpp
#define Multisite_lib_cpp

#ifdef POWERDOWN
	extern void power_down(unsigned short site_no);
#endif

#include "Multisite.cpp"

void get_current_prgfile_dir(char *file_name, char *file_dir, int length) 
{
	char file[201];
	int y = 0,x = 0,len;
	
	file[0]=NULL;

#ifndef V86x235_LOCAL_PROGRAM	
	STRING full_name;
	GetProgramFullName( full_name );
	strcpy( file_dir, full_name );
	char* p = strrchr( file_dir, '\\' );
	if ( p != NULL )
	{
		*(p+1) = 0;
		strcat( file_dir, "multisite\\" );
		file_dir = strlwr( file_dir );
		printf( file_dir );
		return;
	}
#else
	strcpy(file, file_name);
#endif

	len=(int)strlen(file);
	if(len > length) {

		file_dir[0]=NULL;
		return;
	}
	else if(len<2) {
		
		file_dir[0]=NULL;
		return;
	}
	
	for(x = 0; x < len; x++)
	{
		if(file[x] == '\\' )
			if(x>0)
				if(file[x-1]!='\\')
					y++;
	}
	

	strcpy(file_dir, strtok(file, "\\"));
	for(x = 0; x < y-1; x++)
	{
		strcat(file_dir, "\\");
		strcat(file_dir, strtok(NULL, "\\"));
	}
	strcat(file_dir, "\\");
	
	file_dir = _strlwr(file_dir);

	char *pdest = strstr( file_dir, "programs");
	if( pdest != NULL )
		*pdest = '\0';

	printf( file_dir );
	return;
}


int load_pinmap_file(STRING pinmapname)
{
	Text_box box;
	char program_dir[100];
	char temp[100];
	int i;


	if((pinmapname[1]==':')||!strncmp (pinmapname,"//",2)||!strncmp (pinmapname,"\\\\",2))
	{

		for(i=strlen(pinmapname);i>=0;i--)
			if((pinmapname[i]=='/')||(pinmapname[i]=='\\'))
				break;
		

		strncpy(program_dir, pinmapname, i+1);
		program_dir[i+1]='\0';

		strcpy(temp, &pinmapname[i+1]);
		pinmapname=temp;
	}
	else
	{
		get_current_prgfile_dir(__FILE__, program_dir, 100);
		char *pdest = strstr( program_dir, "programs");
		if( pdest == NULL )
			strcat(program_dir,"programs\\multisite\\");
	}

	int stat = 0;

#ifdef VISATE_5x
	read_pinmap_data(CHAR program_dir,pinmapname);
#else
	read_pinmap_data(program_dir,pinmapname);
#endif


	
	printf("MULTISITE SETUP successful (");
	printf(MULTISITE_REV);
	printf(")\n");
	printf("Pinmap file:\n%s%s\n", program_dir,&pinmapname[0]);


#ifdef SMATHVER
	printf("SMATH Ver. ");
	printf(SMATHVER);
	printf(" loaded\n");
#endif


#ifndef ASL1K_NO_CBIT
#ifdef CBITSVER
	printf("CBITS Ver. ");
	printf(CBITSVER);
	printf(" loaded\n");
#endif
#endif

	return(stat);
}


SFLOAT::SFLOAT() {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site]=0;
}

SFLOAT::~SFLOAT() {
}

SFLOAT SFLOAT::operator = (float value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = value;
	return *this;
}

SFLOAT SFLOAT::operator =(class SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = value.get_value(site);
	return *this;
}

SFLOAT SFLOAT::operator+=(float value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] + value;
	return *this;
}

SFLOAT SFLOAT::operator+=(class SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] + value.get_value(site);
	return *this;
}

SFLOAT SFLOAT::operator-=(float value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] - value;
	return *this;
}

SFLOAT SFLOAT::operator-=(class SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] - value.get_value(site);
	return *this;
}

SFLOAT SFLOAT::operator*=(float value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] * value;
	return *this;
}

SFLOAT SFLOAT::operator*=(class SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] * value.get_value(site);
	return *this;
}

SFLOAT SFLOAT::operator/=(float value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] / value;
	return *this;
}

SFLOAT SFLOAT::operator/=(class SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = result[site] / value.get_value(site);
	return *this;
}

void SFLOAT::init() {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = 0;
}

void SFLOAT::set_to(float *value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
		result[site] = value[site];
}

void SFLOAT::set_to(float value, int site) {
		result[site] = value;
}

float* SFLOAT::get_value() {
	return result;
}

float SFLOAT::get_value(int site) {
	return (result[site]);
}

void SFLOAT::reciprocal() {
	for (int site=0; site < CSC_MAX_SITES; site++)
		if (result[site] != 0)
			result[site] = 1/result[site];
}

float* SFLOAT::fabs(SFLOAT value) {
	for (int site=0; site < CSC_MAX_SITES; site++)
			if (value.get_value(site) < 0)
					result[site] = -value.get_value(site);
			else
					result[site] = value.get_value(site);
	return(result);
}

float* SFLOAT::fabs(void) {
	for (int site=0; site < CSC_MAX_SITES; site++)
			if (result[site] < 0)
					result[site] = -result[site];
	return(result);
}



void GetSerialNum (STRING &sernumstr,int this_site)
{
	GetSerialNum (sernumstr);
	int sernum = atoi(sernumstr) - 1;
	for (int site=0; site < CSC_MAX_SITES; site++)
		if (store_active_site[site]) {
			sernum++;
			if (site == this_site)
				site = CSC_MAX_SITES;
		}
	char sernumstr_[10];
	sprintf(sernumstr_,"%d",sernum);
	sernumstr = sernumstr_;
}

#endif

