
























#ifndef SMATHVER

#define SMATHVER "1.12"


extern void s_set_to (sfloat variable, float value);
extern void s_set_to (sdouble variable, double value);
extern void s_set_to (sushort variable, unsigned short value);
extern void s_set_to (sulong variable, unsigned long value);
extern void s_set_to (suint variable, unsigned int value);
extern void s_set_to (sint variable, int value);
extern void s_set_to (sbool variable, int value);
extern void s_set_to (char * variable, char value);


extern void s_copy_to (sfloat var1, sfloat var2);
extern void s_copy_to (sdouble var1, sdouble var2);
extern void s_copy_to (sushort var1, sushort var2);
extern void s_copy_to (sulong var1, sulong var2);
extern void s_copy_to (suint var1, suint var2);
extern void s_copy_to (sint var1, sint var2);
extern void s_copy_to (sbool var1, sbool var2);
extern void s_copy_to (char * var1, char * var2);


extern void s_copy_to (sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_copy_to (sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_set_to (sfloat_wf variable, float value, unsigned int size);
extern void s_set_to (sdouble_wf variable, double value, unsigned int size);


extern void s_set_to (sfloat_wf variable, sfloat s_value, unsigned int size);
extern void s_set_to (sdouble_wf variable, sdouble s_value, unsigned int size);


extern void s_set_to_fabs(sfloat variable);
extern void s_set_to_fabs(sdouble variable);
extern void s_set_to_fabs(sint variable);


extern void s_set_to_fabs (sfloat_wf variable, unsigned int size);
extern void s_set_to_fabs (sdouble_wf variable, unsigned int size);


extern void s_subtract (sfloat result, sfloat var1, sfloat var2);
extern void s_subtract (sdouble result, sdouble var1, sdouble var2);
extern void s_subtract (sushort result, sushort var1, sushort var2);
extern void s_subtract (sulong result, sulong var1, sulong var2);
extern void s_subtract (suint result, suint var1, suint var2);
extern void s_subtract (sint result, sint var1, sint var2);


extern void s_subtract (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_subtract (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_add (sfloat result, sfloat var1, sfloat var2);
extern void s_add (sdouble result, sdouble var1, sdouble var2);
extern void s_add (sushort result, sushort var1, sushort var2);
extern void s_add (sulong result, sulong var1, sulong var2);
extern void s_add (suint result, suint var1, suint var2);
extern void s_add (sint result, sint var1, sint var2);


extern void s_add (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_add (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_scale (sfloat result, sfloat var1, float var2);
extern void s_scale (sdouble result, sdouble var1, double var2);
extern void s_scale (sushort result, sushort var1, unsigned short var2);
extern void s_scale (sulong result, sulong var1, unsigned long var2);
extern void s_scale (suint result, suint var1, unsigned int var2);
extern void s_scale (sint result, sint var1, int var2);


extern void s_scale (sfloat_wf result, sfloat_wf var1, float var2, unsigned int size);
extern void s_scale (sdouble_wf result, sdouble_wf var1, double var2, unsigned int size);


extern void s_offset (sfloat result, sfloat var1, float var2);
extern void s_offset (sdouble result, sdouble var1, double var2);
extern void s_offset (sushort result, sushort var1, unsigned short var2);
extern void s_offset (sulong result, sulong var1, unsigned long var2);
extern void s_offset (suint result, suint var1, unsigned int var2);
extern void s_offset (sint result, sint var1, int var2);


extern void s_offset (sfloat_wf result, sfloat_wf var1, float var2, unsigned int size);
extern void s_offset (sdouble_wf result, sdouble_wf var1, double var2, unsigned int size);


extern void s_multiply (sfloat result, sfloat var1, sfloat var2);
extern void s_multiply (sdouble result, sdouble var1, sdouble var2);
extern void s_multiply (sushort result, sushort var1, sushort var2);
extern void s_multiply (sulong result, sulong var1, sulong var2);
extern void s_multiply (suint result, suint var1, suint var2);
extern void s_multiply (sint result, sint var1, sint var2);


extern void s_multiply (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_multiply (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_divide (sfloat result, sfloat var1, sfloat var2);
extern void s_divide (sdouble result, sdouble var1, sdouble var2);
extern void s_divide (sushort result, sushort var1, sushort var2);
extern void s_divide (sulong result, sulong var1, sulong var2);
extern void s_divide (suint result, suint var1, suint var2);
extern void s_divide (sint result, sint var1, sint var2);


void s_divide (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
void s_divide (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_invert (sfloat result, sfloat var1);
extern void s_invert (sdouble result, sdouble var1);
extern void s_invert (sint result, sint var1);


extern void s_invert (sfloat_wf result, sfloat_wf var1, unsigned int size);
extern void s_invert (sdouble_wf result, sdouble_wf var1, unsigned int size);


extern void s_reciprocal (sfloat result, sfloat var1);
extern void s_reciprocal (sdouble result, sdouble var1);


extern void s_reciprocal (sfloat result, sfloat var1);
extern void s_reciprocal (sdouble result, sdouble var1);


extern void s_pow (sfloat result, sfloat var1, float value);
extern void s_pow (sdouble result, sdouble var1, double value);


extern void s_pow (sfloat_wf result, sfloat_wf var1, float value, unsigned int size);
extern void s_pow (sdouble_wf result, sdouble_wf var1, double value, unsigned int size);


extern void s_log (sfloat result, sfloat var1);
extern void s_log (sdouble result, sdouble var1);


extern void s_log (sfloat_wf result, sfloat_wf var1, unsigned int size);
extern void s_log (sdouble_wf result, sdouble_wf var1, unsigned int size);


extern void s_log10 (sfloat result, sfloat var1);
extern void s_log10 (sdouble result, sdouble var1);


extern void s_log10 (sfloat_wf result, sfloat_wf var1, unsigned int size);
extern void s_log10 (sdouble_wf result, sdouble_wf var1, unsigned int size);


extern void s_log2 (sfloat result, sfloat var1);
extern void s_log2 (sdouble result, sdouble var1);


extern void s_log2 (sfloat_wf result, sfloat_wf var1, unsigned int size);
extern void s_log2 (sdouble_wf result, sdouble_wf var1, unsigned int size);


extern void s_db (sfloat result, sfloat var1);
extern void s_db (sdouble result, sdouble var1);


extern void s_db (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_db (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_mag_db (sfloat result, sfloat var1, sfloat var2);	
extern void s_mag_db (sdouble result, sdouble var1, sfloat var2);


extern void s_mag_db (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size);
extern void s_mag_db (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size);


extern void s_copy (sfloat var1, sfloat var2);
extern void s_copy (sfloat var1, sdouble var2);
extern void s_copy (sfloat var1, sushort var2);
extern void s_copy (sfloat var1, sulong var2);
extern void s_copy (sfloat var1, suint var2);
extern void s_copy (sfloat var1, sint var2);
extern void s_copy (sfloat var1, sbool var2);

extern void s_copy (sdouble var1, sdouble var2);
extern void s_copy (sdouble var1, sfloat var2);
extern void s_copy (sdouble var1, sushort var2);
extern void s_copy (sdouble var1, sulong var2);
extern void s_copy (sdouble var1, suint var2);
extern void s_copy (sdouble var1, sint var2);
extern void s_copy (sdouble var1, sbool var2);

extern void s_copy (sushort var1, sushort var2);
extern void s_copy (sushort var1, sfloat var2);
extern void s_copy (sushort var1, sdouble var2);
extern void s_copy (sushort var1, sulong var2);
extern void s_copy (sushort var1, suint var2);
extern void s_copy (sushort var1, sint var2);
extern void s_copy (sushort var1, sbool var2);

extern void s_copy (sulong var1, sulong var2);
extern void s_copy (sulong var1, sfloat var2);
extern void s_copy (sulong var1, sdouble var2);
extern void s_copy (sulong var1, sushort var2);
extern void s_copy (sulong var1, suint var2);
extern void s_copy (sulong var1, sint var2);
extern void s_copy (sulong var1, sbool var2);

extern void s_copy (suint var1, suint var2);
extern void s_copy (suint var1, sfloat var2);
extern void s_copy (suint var1, sdouble var2);
extern void s_copy (suint var1, sulong var2);
extern void s_copy (suint var1, sushort var2);
extern void s_copy (suint var1, suint var2);
extern void s_copy (suint var1, sbool var2);

extern void s_copy (sint var1, sint var2);
extern void s_copy (sint var1, sfloat var2);
extern void s_copy (sint var1, sdouble var2);
extern void s_copy (sint var1, sulong var2);
extern void s_copy (sint var1, sushort var2);
extern void s_copy (sint var1, suint var2);
extern void s_copy (sint var1, sbool var2);

extern void s_copy (sbool var1, sint var2);
extern void s_copy (sbool var1, sfloat var2);
extern void s_copy (sbool var1, sdouble var2);
extern void s_copy (sbool var1, sulong var2);
extern void s_copy (sbool var1, sushort var2);
extern void s_copy (sbool var1, suint var2);
extern void s_copy (sbool var1, sbool var2);


void s_copy (sfloat_wf var1, sfloat_wf var2, unsigned int size);
void s_copy (sfloat_wf var1, sdouble_wf var2, unsigned int size);
void s_copy (sdouble_wf var1, sfloat_wf var2, unsigned int size);
void s_copy (sdouble_wf var1, sdouble_wf var2, unsigned int size);


void s_calc_R(float *variable, float voltage, short meas_V_I = MEASURE_CURRENT);


extern int s_compare(sfloat var1, float var2, char oper);
extern int s_compare(sdouble var1, double var2, char oper);
extern int s_compare(sushort var1, unsigned short var2, char oper);
extern int s_compare(sulong var1, unsigned long var2, char oper);
extern int s_compare(suint var1, unsigned int var2, char oper);
extern int s_compare(sint var1, int var2, char oper);
extern int s_compare(sbool var1, bool var2, char oper);
extern int s_compare(char *var1, char var2, char oper);

#ifndef LegacyVATE522

typedef enum {MS_FLOAT, MS_DOUBLE, MS_INT, MS_SHORT, MS_LONG, MS_SUINT, MS_SUSHORT, MS_SULONG, MS_BOOL} MsNumIdType;
typedef enum {POS, NEG} TriggerType;	

template <class varType>
class __declspec(dllexport) MS_Number
{
private:
	varType*	ms_value;
	MsNumIdType	ms_id;

public:
	MS_Number();								
	MS_Number(MS_Number<double>& MS_Num);		
	MS_Number(MS_Number<float>& MS_Num);			
	MS_Number(MS_Number<int>& MS_Num);			

	MS_Number(MS_Number<short>& MS_Num);		
	MS_Number(MS_Number<long>& MS_Num);			

	MS_Number(MS_Number<unsigned int>& MS_Num);	
	MS_Number(MS_Number<unsigned short>& MS_Num);	
	MS_Number(MS_Number<unsigned long>& MS_Num);
	MS_Number(MS_Number<bool>& MS_Num);			
	MS_Number(sDouble& s_Num);					
	MS_Number(double *s_num);					
	MS_Number(float *s_num);					
	MS_Number(int *s_num);						

	MS_Number(short *s_num);					
	MS_Number(long *s_num);						

	MS_Number(unsigned int *s_num);				
	MS_Number(unsigned short *s_num);			
	MS_Number(unsigned long *s_num);			
	MS_Number(bool *s_num);						
	MS_Number(double num);						
	MS_Number(float num);						
	MS_Number(int num);							

	MS_Number(short num);						
	MS_Number(long num);						

	MS_Number(unsigned int num);				
	MS_Number(unsigned short num);				
	MS_Number(unsigned long num);				
	MS_Number(bool num);						
		
	~MS_Number();

	varType get_value(int site);
	void set_value(int site, varType num);
	MsNumIdType get_type(void);
	void init(void);

	void copy_to(sDouble &s_Num);
	void copy_to(float *s_num);
	void copy_to(double *s_num);
	void copy_to(int *s_num);
	void copy_to(unsigned int *s_num);
	void copy_to(unsigned short *s_num);
	void copy_to(unsigned long *s_num);
	void copy_to(bool *s_num);
	varType & operator[](int site);
	varType & operator()(int site);
	MS_Number<varType> operator=(const MS_Number<varType>& MS_Num);	
	MS_Number<varType> operator+(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator-(MS_Number<varType> MS_Num);	
	MS_Number<varType> operator*(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator/(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator%(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator+=(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator-=(MS_Number<varType> MS_Num);	
	MS_Number<varType> operator*=(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator/=(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator%=(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator>>(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator<<(MS_Number<varType> MS_Num);	
	MS_Number<varType> operator>>=(MS_Number<varType> MS_Num);	
	MS_Number<varType> operator<<=(MS_Number<varType> MS_Num);	
	MS_Number<bool> operator==(MS_Number<varType> MS_Num);		
	MS_Number<bool> operator!=(MS_Number<varType> MS_Num);			
	MS_Number<bool> operator>(MS_Number<varType> MS_Num);		
	MS_Number<bool> operator<(MS_Number<varType> MS_Num);		
	MS_Number<bool> operator>=(MS_Number<varType> MS_Num);		
	MS_Number<bool> operator<=(MS_Number<varType> MS_Num);		
	MS_Number<bool> operator!();									
	MS_Number<varType> operator&&(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator||(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator~();									
	MS_Number<varType> operator&(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator|(MS_Number<varType> MS_Num);		
	MS_Number<varType> operator^(MS_Number<varType> MS_Num);	
	MS_Number<double> math_func(double (*pf)(double));			
	MS_Number<double> math_func2(double (*pf)(double, double), MS_Number<varType> MS_Num);	
	MS_Number<double> sign(void);									
	MS_Number<double> round(unsigned short dec_digits=0);			

	varType get_max_site(int *site=NULL);						
	varType get_min_site(int *site=NULL);							
	MS_Number<varType> clip_max(MS_Number<varType> MS_Num);		
	MS_Number<varType> clip_min(MS_Number<varType> MS_Num);		
	MS_Number<bool> is_between(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2, bool include_lims=false);	
	MS_Number<bool> is_between(varType Num1, varType Num2, bool include_lims=false);							

};

typedef MS_Number<double>			MSDOUBLE;
typedef MS_Number<float>			MSFLOAT;
typedef MS_Number<bool>				MSBOOL;
typedef MS_Number<int>				MSINT;
typedef MS_Number<unsigned int>		MSUINT;
typedef MS_Number<unsigned short>	MSUSHORT;
typedef MS_Number<unsigned long>	MSULONG;
typedef MS_Number<unsigned short>	MSSHORT;	
typedef MS_Number<unsigned long>	MSLONG;		

extern MS_Number<double> acos(MS_Number<double> MS_Num);
extern MS_Number<double> acos(MS_Number<float> MS_Num);
extern MS_Number<double> acos(double *s_num);
extern MS_Number<double> acos(float *s_num);

extern MS_Number<double> asin(MS_Number<double> MS_Num);
extern MS_Number<double> asin(MS_Number<float> MS_Num);
extern MS_Number<double> asin(double *s_num);
extern MS_Number<double> asin(float *s_num);

extern MS_Number<double> atan(MS_Number<double> MS_Num);
extern MS_Number<double> atan(MS_Number<float> MS_Num);
extern MS_Number<double> atan(double *s_num);
extern MS_Number<double> atan(float *s_num);

extern MS_Number<double> ceil(MS_Number<double> MS_Num);
extern MS_Number<double> ceil(MS_Number<float> MS_Num);
extern MS_Number<double> ceil(double *s_num);
extern MS_Number<double> ceil(float *s_num);

extern MS_Number<double> cos(MS_Number<double> MS_Num);
extern MS_Number<double> cos(MS_Number<float> MS_Num);
extern MS_Number<double> cos(double *s_num);
extern MS_Number<double> cos(float *s_num);

extern MS_Number<double> cosh(MS_Number<double> MS_Num);
extern MS_Number<double> cosh(MS_Number<float> MS_Num);
extern MS_Number<double> cosh(double *s_num);
extern MS_Number<double> cosh(float *s_num);

extern MS_Number<double> exp(MS_Number<double> MS_Num);
extern MS_Number<double> exp(MS_Number<float> MS_Num);
extern MS_Number<double> exp(double *s_num);
extern MS_Number<double> exp(float *s_num);

extern MS_Number<double> exp2(MS_Number<double> MS_Num);
extern MS_Number<double> exp2(MS_Number<float> MS_Num);
extern MS_Number<double> exp2(double *s_num);
extern MS_Number<double> exp2(float *s_num);

extern MS_Number<double> exp10(MS_Number<double> MS_Num);
extern MS_Number<double> exp10(MS_Number<float> MS_Num);
extern MS_Number<double> exp10(double *s_num);
extern MS_Number<double> exp10(float *s_num);

extern MS_Number<double> fabs(MS_Number<double> MS_Num);
extern MS_Number<double> fabs(MS_Number<float> MS_Num);
extern MS_Number<double> fabs(double *s_num);
extern MS_Number<double> fabs(float *s_num);

extern MS_Number<double> floor(MS_Number<double> MS_Num);
extern MS_Number<double> floor(MS_Number<float> MS_Num);
extern MS_Number<double> floor(double *s_num);
extern MS_Number<double> floor(float *s_num);

extern MS_Number<double> log(MS_Number<double> MS_Num);
extern MS_Number<double> log(MS_Number<float> MS_Num);
extern MS_Number<double> log(double *s_num);
extern MS_Number<double> log(float *s_num);

extern MS_Number<double> log10(MS_Number<double> MS_Num);
extern MS_Number<double> log10(MS_Number<float> MS_Num);
extern MS_Number<double> log10(double *s_num);
extern MS_Number<double> log10(float *s_num);

extern MS_Number<double> log2(MS_Number<double> MS_Num);
extern MS_Number<double> log2(MS_Number<float> MS_Num);
extern MS_Number<double> log2(double *s_num);
extern MS_Number<double> log2(float *s_num);

extern MS_Number<double> sin(MS_Number<double> MS_Num);
extern MS_Number<double> sin(MS_Number<float> MS_Num);
extern MS_Number<double> sin(double *s_num);
extern MS_Number<double> sin(float *s_num);

extern MS_Number<double> sinh(MS_Number<double> MS_Num);
extern MS_Number<double> sinh(MS_Number<float> MS_Num);
extern MS_Number<double> sinh(double *s_num);
extern MS_Number<double> sinh(float *s_num);

extern MS_Number<double> tan(MS_Number<double> MS_Num);
extern MS_Number<double> tan(MS_Number<float> MS_Num);
extern MS_Number<double> tan(double *s_num);
extern MS_Number<double> tan(float *s_num);

extern MS_Number<double> tanh(MS_Number<double> MS_Num);
extern MS_Number<double> tanh(MS_Number<float> MS_Num);
extern MS_Number<double> tanh(double *s_num);
extern MS_Number<double> tanh(float *s_num);

extern MS_Number<double> sqrt(MS_Number<double> MS_Num);
extern MS_Number<double> sqrt(MS_Number<float> MS_Num);
extern MS_Number<double> sqrt(double *s_num);
extern MS_Number<double> sqrt(float *s_num);

extern MS_Number<double> pow(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, double *s_num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, double *s_num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, float *s_num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, float *s_num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, double num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, double num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, float num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, float num2);
extern MS_Number<double> pow(MS_Number<double> MS_Num1, int num2);
extern MS_Number<double> pow(MS_Number<float> MS_Num1, int num2);

extern MS_Number<double> fmod(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, double *s_num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, double *s_num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, float *s_num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, float *s_num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, double num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, double num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, float num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, float num2);
extern MS_Number<double> fmod(MS_Number<double> MS_Num1, int num2);
extern MS_Number<double> fmod(MS_Number<float> MS_Num1, int num2);

extern MS_Number<double> sign(MS_Number<double> MS_Num);
extern MS_Number<double> sign(MS_Number<float> MS_Num);
extern MS_Number<double> sign(double *s_num);
extern MS_Number<double> sign(float *s_num);

extern MS_Number<double> round(MS_Number<double> MS_Num, unsigned short dec_digits=0);
extern MS_Number<double> round(MS_Number<float> MS_Num, unsigned short dec_digits=0);
extern MS_Number<double> round(double *s_num, unsigned short dec_digits=0);
extern MS_Number<double> round(float *s_num, unsigned short dec_digits=0);

extern MS_Number<double>			fmax(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<float>				fmax(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<int>				fmax(MS_Number<int> MS_Num1, MS_Number<int> MS_Num2);
extern MS_Number<short>				fmax(MS_Number<short> MS_Num1, MS_Number<short> MS_Num2);	
extern MS_Number<long>				fmax(MS_Number<long> MS_Num1, MS_Number<long> MS_Num2);		
extern MS_Number<unsigned int>		fmax(MS_Number<unsigned int> MS_Num1, MS_Number<unsigned int> MS_Num2);
extern MS_Number<unsigned short>	fmax(MS_Number<unsigned short> MS_Num1, MS_Number<unsigned short> MS_Num2);
extern MS_Number<unsigned long>		fmax(MS_Number<unsigned long> MS_Num1, MS_Number<unsigned long> MS_Num2);

extern MS_Number<double>			fmin(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<float>				fmin(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<int>				fmin(MS_Number<int> MS_Num1, MS_Number<int> MS_Num2);
extern MS_Number<short>				fmin(MS_Number<short> MS_Num1, MS_Number<short> MS_Num2);	
extern MS_Number<long>				fmin(MS_Number<long> MS_Num1, MS_Number<long> MS_Num2);		
extern MS_Number<unsigned int>		fmin(MS_Number<unsigned int> MS_Num1, MS_Number<unsigned int> MS_Num2);
extern MS_Number<unsigned short>	fmin(MS_Number<unsigned short> MS_Num1, MS_Number<unsigned short> MS_Num2);
extern MS_Number<unsigned long>		fmin(MS_Number<unsigned long> MS_Num1, MS_Number<unsigned long> MS_Num2);

extern MS_Number<double> db(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> db(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> db(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> db(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> db(double *s_num1, double *s_num2);
extern MS_Number<double> db(float *s_num1, float *s_num2);

extern MS_Number<double> mag_db(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> mag_db(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2);
extern MS_Number<double> mag_db(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> mag_db(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2);
extern MS_Number<double> mag_db(double *s_num1, double *s_num2);
extern MS_Number<double> mag_db(float *s_num1, float *s_num2);


extern double			get_max_site(MS_Number<double> MS_Num,			int *site=NULL);
extern float			get_max_site(MS_Number<float> MS_Num,			int *site=NULL);
extern int				get_max_site(MS_Number<int> MS_Num,				int *site=NULL);
extern short			get_max_site(MS_Number<short> MS_Num,			int *site=NULL);
extern long				get_max_site(MS_Number<long> MS_Num,			int *site=NULL);
extern unsigned int		get_max_site(MS_Number<unsigned int> MS_Num,	int *site=NULL);
extern unsigned short	get_max_site(MS_Number<unsigned short> MS_Num,	int *site=NULL);
extern unsigned long	get_max_site(MS_Number<unsigned long> MS_Num,	int *site=NULL);
extern bool				get_max_site(MS_Number<bool> MS_Num,			int *site=NULL);

extern double			get_min_site(MS_Number<double> MS_Num,			int *site=NULL);
extern float			get_min_site(MS_Number<float> MS_Num,			int *site=NULL);
extern int				get_min_site(MS_Number<int> MS_Num,				int *site=NULL);
extern short			get_min_site(MS_Number<short> MS_Num,			int *site=NULL);
extern long				get_min_site(MS_Number<long> MS_Num,			int *site=NULL);
extern unsigned int		get_min_site(MS_Number<unsigned int> MS_Num,	int *site=NULL);
extern unsigned short	get_min_site(MS_Number<unsigned short> MS_Num,	int *site=NULL);
extern unsigned long	get_min_site(MS_Number<unsigned long> MS_Num,	int *site=NULL);
extern bool				get_min_site(MS_Number<bool> MS_Num,			int *site=NULL);

extern MS_Number<double>			clip_max(MS_Number<double> MS_Num1,			MS_Number<double> MS_Num2);
extern MS_Number<float>				clip_max(MS_Number<float> MS_Num1,			MS_Number<float> MS_Num2);
extern MS_Number<int>				clip_max(MS_Number<int> MS_Num1,			MS_Number<int> MS_Num2);
extern MS_Number<short>				clip_max(MS_Number<short> MS_Num1,			MS_Number<short> MS_Num2);
extern MS_Number<long>				clip_max(MS_Number<long> MS_Num1,			MS_Number<long> MS_Num2);
extern MS_Number<unsigned int>		clip_max(MS_Number<unsigned int> MS_Num1,	MS_Number<unsigned int> MS_Num2);
extern MS_Number<unsigned short>	clip_max(MS_Number<unsigned short> MS_Num1,	MS_Number<unsigned short> MS_Num2);
extern MS_Number<unsigned long>		clip_max(MS_Number<unsigned long> MS_Num1,	MS_Number<unsigned long> MS_Num2);

extern MS_Number<double>			clip_min(MS_Number<double> MS_Num1,			MS_Number<double> MS_Num2);
extern MS_Number<float>				clip_min(MS_Number<float> MS_Num1,			MS_Number<float> MS_Num2);
extern MS_Number<int>				clip_min(MS_Number<int> MS_Num1,			MS_Number<int> MS_Num2);
extern MS_Number<short>				clip_min(MS_Number<short> MS_Num1,			MS_Number<short> MS_Num2);
extern MS_Number<long>				clip_min(MS_Number<long> MS_Num1,			MS_Number<long> MS_Num2);
extern MS_Number<unsigned int>		clip_min(MS_Number<unsigned int> MS_Num1,	MS_Number<unsigned int> MS_Num2);
extern MS_Number<unsigned short>	clip_min(MS_Number<unsigned short> MS_Num1,	MS_Number<unsigned short> MS_Num2);
extern MS_Number<unsigned long>		clip_min(MS_Number<unsigned long> MS_Num1,	MS_Number<unsigned long> MS_Num2);

extern MS_Number<bool>				is_between(MS_Number<double> MS_Num,			MS_Number<double> MS_NumMin,			MS_Number<double> MS_NumMax,			bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<float> MS_Num,				MS_Number<float> MS_NumMin,				MS_Number<float> MS_NumMax,				bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<int> MS_Num,				MS_Number<int> MS_NumMin,				MS_Number<int> MS_NumMax,				bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<short> MS_Num,				MS_Number<short> MS_NumMin,				MS_Number<short> MS_NumMax,				bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<long> MS_Num,				MS_Number<long> MS_NumMin,				MS_Number<long> MS_NumMax,				bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned int> MS_Num,		MS_Number<unsigned int> MS_NumMin,		MS_Number<unsigned int> MS_NumMax,		bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned short> MS_Num,	MS_Number<unsigned short> MS_NumMin,	MS_Number<unsigned short> MS_NumMax,	bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned long> MS_Num,		MS_Number<unsigned long> MS_NumMin,		MS_Number<unsigned long> MS_NumMax,		bool include_lims=false);

extern MS_Number<bool>				is_between(MS_Number<double> MS_Num,			double NumMin,			double NumMax,			bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<float> MS_Num,				float NumMin,			float NumMax,			bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<int> MS_Num,				int NumMin,				int NumMax,				bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<short> MS_Num,				short NumMin,			short NumMax,			bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<long> MS_Num,				long NumMin,			long NumMax,			bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned int> MS_Num,		unsigned int NumMin,	unsigned int NumMax,	bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned short> MS_Num,	unsigned short NumMin,	unsigned short NumMax,	bool include_lims=false);
extern MS_Number<bool>				is_between(MS_Number<unsigned long> MS_Num,		unsigned long NumMin,	unsigned long NumMax,	bool include_lims=false);


class MS_Status
{
private:
	BOOL*	ms_value;
	bool	ms_ext_data;
public:
	MS_Status();								
	MS_Status(MS_Status& MS_Num);				
	MS_Status(MS_Number<int>& MS_Num);			
	MS_Status(MS_Number<short>& MS_Num);		
	MS_Status(MS_Number<long>& MS_Num);			
	MS_Status(MS_Number<unsigned int>& MS_Num);	
	MS_Status(MS_Number<unsigned short>& MS_Num);	
	MS_Status(MS_Number<unsigned long>& MS_Num);
	MS_Status(MS_Number<bool>& MS_Num);			
	MS_Status(int *s_num);						
	MS_Status(int num);							
	MS_Status(short num);						
	MS_Status(long num);						
	MS_Status(unsigned int num);				
	MS_Status(unsigned short num);				
	MS_Status(unsigned long num);				
	MS_Status(bool num);						
	~MS_Status();

	BOOL get_value(int site);
	void set_value(int site, BOOL num);
	void init(void);								
	void reset(void);							

	void copy_to(MS_Number<int>& MS_Num);
	void copy_to(MS_Number<short>& MS_Num);
	void copy_to(MS_Number<long>& MS_Num);
	void copy_to(MS_Number<unsigned int>& MS_Num);
	void copy_to(MS_Number<unsigned short>& MS_Num);
	void copy_to(MS_Number<unsigned long>& MS_Num);
	void copy_to(MS_Number<bool>& MS_Num);
	void copy_to(double *s_num);
	void copy_to(float *s_num);
	void copy_to(int *s_num);
	void copy_to(short *s_num);
	void copy_to(long *s_num);
	void copy_to(unsigned int *s_num);
	void copy_to(unsigned short *s_num);
	void copy_to(unsigned long *s_num);
	void copy_to(bool *s_num);
	BOOL & operator[](int site);
	BOOL & operator()(int site);
	MS_Status operator=(const MS_Status& MS_Num);
	MS_Status operator+(MS_Status MS_Num);			
	MS_Status operator-(MS_Status MS_Num);			
	MS_Status operator+=(MS_Status MS_Num);		
	MS_Status operator-=(MS_Status MS_Num);		
	MS_Status operator==(MS_Status MS_Num);		
	MS_Status operator!=(MS_Status MS_Num);		
	MS_Status operator!();						
	MS_Status operator&&(MS_Status MS_Num);		
	MS_Status operator||(MS_Status MS_Num);		
};

extern	MS_Status	Active_Site;
typedef MS_Status	SITE_STATUS;






template <class arrType>
class __declspec(dllexport) MS_Array
{
protected:
	arrType**		ms_array;	
	MsNumIdType		ms_id;			
	int				ms_ary_size;
	bool			ms_ext_data;

public:
	MS_Array();											
	MS_Array(int size);										
	MS_Array(MS_Array<double>& MS_Ary);					
	MS_Array(MS_Array<float>& MS_Ary);					
	MS_Array(MS_Array<int>& MS_Ary);					
	MS_Array(MS_Number<double>& MS_Num, int size);		
	MS_Array(MS_Number<float>& MS_Num, int size);		
	MS_Array(MS_Number<int>& MS_Num, int size);				

	MS_Array(MS_Number<short>& MS_Num, int size);		
	MS_Array(MS_Number<long>& MS_Num, int size);		

	MS_Array(MS_Number<unsigned int>& MS_Num, int size);
	MS_Array(MS_Number<unsigned short>& MS_Num, int size);
	MS_Array(MS_Number<unsigned long>& MS_Num, int size);
	MS_Array(MS_Number<bool>& MS_Num, int size);		
	MS_Array(double *, int size);						
	MS_Array(float *, int size);						
	MS_Array(int *, int size);							

	MS_Array(short *, int size);						
	MS_Array(long *, int size);					

	MS_Array(unsigned int *, int size);					
	MS_Array(unsigned short *, int size);				
	MS_Array(unsigned long *, int size);				
	MS_Array(bool *, int size);								
	MS_Array(double, int size);							
	MS_Array(float, int size);							
	MS_Array(int, int size);							

	MS_Array(short, int size);							
	MS_Array(long, int size);							

	MS_Array(unsigned int, int size);					
	MS_Array(unsigned short, int size);					
	MS_Array(unsigned long, int size);					
	MS_Array(bool, int size);							
	~MS_Array();

	arrType get_value(int site, int sample);
	void set_value(int site, int sample, arrType num);


	MS_Number<arrType> get_value(int sample);
	void set_value(int sample, MS_Number<arrType> MS_Num);


	MsNumIdType get_type(void);
	int get_size(void);
	void init(void);
	void init(int size);

	arrType* operator[](int site);
	MS_Array<arrType> operator=(const MS_Array<arrType>& MS_Ary);

	MS_Array<arrType> operator=(double	Value);					
	MS_Array<arrType> operator=(float	Value);					
	MS_Array<arrType> operator=(int	Value);						
	MS_Array<arrType> operator=(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator=(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator=(MS_Number<int>		MsVal);		


	MS_Array<arrType> operator+(MS_Array<arrType> MS_Ary);		

	MS_Array<arrType> operator+(double	Value);						
	MS_Array<arrType> operator+(float	Value);					
	MS_Array<arrType> operator+(int	Value);						
	MS_Array<arrType> operator+(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator+(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator+(MS_Number<int>		MsVal);		


	MS_Array<arrType> operator-(MS_Array<arrType> MS_Ary);			

	MS_Array<arrType> operator-(double	Value);					
	MS_Array<arrType> operator-(float	Value);					
	MS_Array<arrType> operator-(int	Value);						
	MS_Array<arrType> operator-(MS_Number<double>	MsVal);			
	MS_Array<arrType> operator-(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator-(MS_Number<int>		MsVal);		


	MS_Array<arrType> operator*(MS_Array<arrType> MS_Ary);		

	MS_Array<arrType> operator*(double	Value);						
	MS_Array<arrType> operator*(float	Value);					
	MS_Array<arrType> operator*(int	Value);							
	MS_Array<arrType> operator*(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator*(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator*(MS_Number<int>		MsVal);		


	MS_Array<arrType> operator/(MS_Array<arrType> MS_Ary);		

	MS_Array<arrType> operator/(double	Value);					
	MS_Array<arrType> operator/(float	Value);					
	MS_Array<arrType> operator/(int	Value);						
	MS_Array<arrType> operator/(MS_Number<double>	MsVal);			
	MS_Array<arrType> operator/(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator/(MS_Number<int>		MsVal);			


	MS_Array<arrType> operator+=(MS_Array<arrType> MS_Ary);		

	MS_Array<arrType> operator+=(double	Value);					
	MS_Array<arrType> operator+=(float	Value);					
	MS_Array<arrType> operator+=(int	Value);					
	MS_Array<arrType> operator+=(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator+=(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator+=(MS_Number<int>		MsVal);		
	

	MS_Array<arrType> operator-=(MS_Array<arrType> MS_Ary);		
	
	MS_Array<arrType> operator-=(double	Value);					
	MS_Array<arrType> operator-=(float	Value);					
	MS_Array<arrType> operator-=(int	Value);					
	MS_Array<arrType> operator-=(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator-=(MS_Number<float>	MsVal);	
	MS_Array<arrType> operator-=(MS_Number<int>		MsVal);		
	

	MS_Array<arrType> operator*=(MS_Array<arrType> MS_Ary);		
	
	MS_Array<arrType> operator*=(double	Value);					
	MS_Array<arrType> operator*=(float	Value);					
	MS_Array<arrType> operator*=(int	Value);					
	MS_Array<arrType> operator*=(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator*=(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator*=(MS_Number<int>		MsVal);		
	

	MS_Array<arrType> operator/=(MS_Array<arrType> MS_Ary);		

	MS_Array<arrType> operator/=(double	Value);					
	MS_Array<arrType> operator/=(float	Value);					
	MS_Array<arrType> operator/=(int	Value);					
	MS_Array<arrType> operator/=(MS_Number<double>	MsVal);		
	MS_Array<arrType> operator/=(MS_Number<float>	MsVal);		
	MS_Array<arrType> operator/=(MS_Number<int>		MsVal);		






			
		



	MS_Array<arrType>  Abs(int Start=-1, int Stop=-1);		
	MS_Number<arrType> Mean(int Start=-1, int Stop=-1);			
	MS_Number<arrType> Rms(int Start=-1, int Stop=-1);			
	MS_Number<arrType> Stdev(int Start=-1, int Stop=-1);		
	MS_Number<arrType> Min(int Start=-1, int Stop=-1);			
	MS_Number<arrType> Max(int Start=-1, int Stop=-1);			
	MS_Number<arrType> Least(int Start=-1, int Stop=-1);		
	void mean_stdev_rms(MS_Number<arrType> &Mean, MS_Number<arrType> &Stdev, MS_Number<arrType> &Rms, int Start=-1, int Stop=-1);					
	void min_max_idx(MS_Number<arrType> &Min, MS_Number<arrType> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx, int Start=-1, int Stop=-1);	
	void least_idx(MS_Number<arrType> &Least, MS_Number<int> &LeastIdx, int Start=-1, int Stop=-1);


	MS_Array<arrType>  ClipMin(MS_Number<double> ClipMinVal, MS_Number<int> &Idx=MS_Number<int>(-1), MS_Number<int> Start=-1, MS_Number<int> Stop=-1);	
	MS_Array<arrType>  ClipMax(MS_Number<double> ClipMaxVal, MS_Number<int> &Idx=MS_Number<int>(-1), MS_Number<int> Start=-1, MS_Number<int> Stop=-1);
	MS_Number<int> Trigger(MS_Number<double> TrigThreshold, TriggerType Polarity, MS_Number<int> Start=-1, MS_Number<int> Stop=-1);	

};

class MSDOUBLE_WF: public MS_Array<double>
{
public:

	MSDOUBLE_WF()												: MS_Array<double>(){};			
	MSDOUBLE_WF(int size)										: MS_Array<double>(size){};		
	MSDOUBLE_WF(MS_Array<double>& MS_Ary)						: MS_Array<double>(MS_Ary){};	
	MSDOUBLE_WF(MS_Array<float>& MS_Ary)						: MS_Array<double>(MS_Ary){};	
	MSDOUBLE_WF(MS_Array<int>& MS_Ary) 							: MS_Array<double>(MS_Ary){};		
	MSDOUBLE_WF(MS_Number<double>& MS_Num, int size)			: MS_Array<double>(MS_Num, size){};
	MSDOUBLE_WF(MS_Number<float>& MS_Num, int size)				: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(MS_Number<int>& MS_Num, int size)				: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(MS_Number<unsigned int>& MS_Num, int size)		: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(MS_Number<unsigned short>& MS_Num, int size)	: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(MS_Number<unsigned long>& MS_Num, int size)		: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(MS_Number<bool>& MS_Num, int size)				: MS_Array<double>(MS_Num, size){};	
	MSDOUBLE_WF(double *s_num, int size)						: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(float *s_num, int size)							: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(int *s_num, int size)							: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(unsigned int *s_num, int size)					: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(unsigned short *s_num, int size)				: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(unsigned long *s_num, int size)					: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(bool *s_num, int size)							: MS_Array<double>(s_num, size){};	
	MSDOUBLE_WF(double num, int size)							: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(float num, int size)							: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(int num, int size)								: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(unsigned int num, int size)						: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(unsigned short num, int size)					: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(unsigned long num, int size)					: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(bool num, int size)								: MS_Array<double>(num, size){};	
	MSDOUBLE_WF(double **s_double_wf, int size);
	~MSDOUBLE_WF(){};
	void init(double **s_double_wf, int size);

#ifdef AFX_SDSP_H_INCLUDED

	CSC_STATUS copy_to(Csdsp *sdsp_ptr, int site, WF & s_wave, char * wf_name, const int & data_type);	
#endif	

};

class MSFLOAT_WF: public MS_Array<float>
{
public:

	MSFLOAT_WF()												: MS_Array<float>(){};				
	MSFLOAT_WF(int size)										: MS_Array<float>(size){};			
	MSFLOAT_WF(MS_Array<double>& MS_Ary)						: MS_Array<float>(MS_Ary){};		
	MSFLOAT_WF(MS_Array<float>& MS_Ary)							: MS_Array<float>(MS_Ary){};		
	MSFLOAT_WF(MS_Array<int>& MS_Ary) 							: MS_Array<float>(MS_Ary){};		
	MSFLOAT_WF(MS_Number<double>& MS_Num, int size)				: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<float>& MS_Num, int size)				: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<int>& MS_Num, int size)				: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<unsigned int>& MS_Num, int size)		: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<unsigned short>& MS_Num, int size)		: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<unsigned long>& MS_Num, int size)		: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(MS_Number<bool>& MS_Num, int size)				: MS_Array<float>(MS_Num, size){};	
	MSFLOAT_WF(double *s_num, int size)							: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(float *s_num, int size)							: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(int *s_num, int size)							: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(unsigned int *s_num, int size)					: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(unsigned short *s_num, int size)					: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(unsigned long *s_num, int size)					: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(bool *s_num, int size)							: MS_Array<float>(s_num, size){};	
	MSFLOAT_WF(double num, int size)							: MS_Array<float>(num, size){};		
	MSFLOAT_WF(float num, int size)								: MS_Array<float>(num, size){};		
	MSFLOAT_WF(int num, int size)								: MS_Array<float>(num, size){};		
	MSFLOAT_WF(unsigned int num, int size)						: MS_Array<float>(num, size){};		
	MSFLOAT_WF(unsigned short num, int size)					: MS_Array<float>(num, size){};		
	MSFLOAT_WF(unsigned long num, int size)						: MS_Array<float>(num, size){};		
	MSFLOAT_WF(bool num, int size)								: MS_Array<float>(num, size){};		
	MSFLOAT_WF(float **s_float_wf, int size);
	~MSFLOAT_WF(){};
	void init(float **s_float_wf, int size);

#ifdef AFX_SDSP_H_INCLUDED

	CSC_STATUS copy_to(Csdsp *sdsp_ptr, int site, WF & s_wave, char * wf_name, const int & data_type);	
#endif	
};


extern MS_Number<double> ms_mean (MS_Array<double> MS_Ary);

extern MS_Number<float> ms_mean (MS_Array<float> MS_Ary);	
extern MS_Number<double> ms_mean (MSDOUBLE_WF MS_Ary);
extern MS_Number<float> ms_mean (MSFLOAT_WF MS_Ary);		

extern MS_Number<double> ms_rms (MS_Array<double> MS_Ary);

extern MS_Number<float> ms_rms (MS_Array<float> MS_Ary);	
extern MS_Number<double> ms_rms (MSDOUBLE_WF MS_Ary);
extern MS_Number<float> ms_rms (MSFLOAT_WF MS_Ary);			

extern MS_Number<double> ms_min (MS_Array<double> MS_Ary);

extern MS_Number<float> ms_min (MS_Array<float> MS_Ary);	
extern MS_Number<double> ms_min (MSDOUBLE_WF MS_Ary);
extern MS_Number<float> ms_min (MSFLOAT_WF MS_Ary);			

extern MS_Number<double> ms_max (MS_Array<double> MS_Ary);

extern MS_Number<float> ms_max (MS_Array<float> MS_Ary);	
extern MS_Number<double> ms_max (MSDOUBLE_WF MS_Ary);
extern MS_Number<float> ms_max (MSFLOAT_WF MS_Ary);			





extern void mean_std_rms (MS_Array<double> MS_Ary, MS_Number<double> &Mean, MS_Number<double> &Std, MS_Number<double> &Rms, int Start, int Stop);	
extern void mean_std_rms (MS_Array<float> MS_Ary, MS_Number<float> &Mean, MS_Number<float> &Std, MS_Number<float> &Rms, int Start, int Stop);		
extern void mean_std_rms (MSDOUBLE_WF MS_Ary, MS_Number<double> &Mean, MS_Number<double> &Std, MS_Number<double> &Rms, int Start, int Stop);		
extern void mean_std_rms (MSFLOAT_WF MS_Ary, MS_Number<float> &Mean, MS_Number<float> &Std, MS_Number<float> &Rms, int Start, int Stop);			

extern void min_max_idx (MS_Array<double> MS_Ary, int Start, int Stop, MS_Number<double> &Min, MS_Number<double> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx);

extern void min_max_idx (MS_Array<float> MS_Ary, int Start, int Stop, MS_Number<float> &Min, MS_Number<float> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx);	
extern void min_max_idx (MSDOUBLE_WF MS_Ary, int Start, int Stop, MS_Number<double> &Min, MS_Number<double> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx);
extern void min_max_idx (MSDOUBLE_WF MS_Ary, int Start, int Stop, MS_Number<float> &Min, MS_Number<float> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx);	

#ifdef AFX_SDSP_H_INCLUDED

#endif	



extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, unsigned short fail_bin, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, unsigned short fail_bin, schar notes);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, MS_Number<unsigned short> fail_bin, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, MS_Number<unsigned short> fail_bin, schar notes);



extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned int>	 min_val,MS_Number<unsigned int>	  max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned long > min_val,MS_Number<unsigned long>  max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, unsigned short fail_bin,MS_Number<int>			 min_val,MS_Number<int>			  max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, unsigned short fail_bin,MS_Number<float>			 min_val,MS_Number<float>		  max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, unsigned short fail_bin,MS_Number<double>         min_val,MS_Number<double>         max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, unsigned short fail_bin,MS_Number<bool>			 min_val,MS_Number<bool>			  max_val, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned int>	  min_val,MS_Number<unsigned int>   max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, unsigned short fail_bin,MS_Number<unsigned long>  min_val,MS_Number<unsigned long>  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, unsigned short fail_bin,MS_Number<int>			  min_val,MS_Number<int>			   max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, unsigned short fail_bin,MS_Number<float>		  min_val,MS_Number<float>		   max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, unsigned short fail_bin,MS_Number<double>	      min_val,MS_Number<double>	       max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, unsigned short fail_bin,MS_Number<bool>			  min_val,MS_Number<bool>		   max_val, schar notes);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned int>	min_val,MS_Number<unsigned int> 	 max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned short>	min_val,MS_Number<unsigned short> max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned long>	min_val,MS_Number<unsigned long>	 max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<int>			min_val,MS_Number<int>			 max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<float>			min_val,MS_Number<float>			 max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<double>			min_val,MS_Number<double>		 max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<bool>			min_val,MS_Number<bool>			 max_val, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, MS_Number<unsigned int>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned int>	 min_val,MS_Number<unsigned int>	  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned long>	 min_val,MS_Number<unsigned long>  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<int>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<int>			 min_val,MS_Number<int>			  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<float>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<float>			 min_val,MS_Number<float>		  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<double>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<double>		 min_val,MS_Number<double>		  max_val, schar notes);
extern void  data_log(test_function& func, short test_no, MS_Number<bool>			test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<bool>    	     min_val,MS_Number<bool>    	      max_val, schar notes);


extern void  dc_force(short pin,		float current,				MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,		double current,				MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,		MS_Number<float> current,	float voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,		MS_Number<float> current,	double voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,		MS_Number<float> current,	MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list,	float current,				MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list,	double current,				MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list,	MS_Number<float> *current,	float voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list,	MS_Number<float> *current,	double voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list,	MS_Number<float> *current,	MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);

extern void  cap_force(short pin, short force_mode, float transition_time,		float current,				MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin, short force_mode, float transition_time,		double current,				MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin, short force_mode, float transition_time,		MS_Number<float> current,	float voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin, short force_mode, float transition_time,		MS_Number<float> current,	double voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin, short force_mode, float transition_time,		MS_Number<float> current,	MS_Number<float> voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list, short force_mode, float transition_time,	float current,				MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list, short force_mode, float transition_time,	double current,				MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list, short force_mode, float transition_time,	MS_Number<float> *current,	float voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list, short force_mode, float transition_time,	MS_Number<float> *current,	double voltage,				short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list, short force_mode, float transition_time,	MS_Number<float> *current,	MS_Number<float> *voltage,	short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);

extern void dc_measure(short pin,short mode, MS_Number<double> &result ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short wait_us = 200);
extern void dc_measure(short pin_list, short mode, MS_Number<double> *result_list, short ave_num = 1, short d_range = NO_DIFF_RANGE, short wait_us = 200);
extern void dc_measure(short pin,short mode, MS_Number<float> &result ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short wait_us = 200);
extern void dc_measure(short pin_list, short mode, MS_Number<float> *result_list, short ave_num = 1, short d_range = NO_DIFF_RANGE, short wait_us = 200);




extern void tmu_read(short pin, MS_Number<double> &result, double timeout = 10e-3);	
extern void tmu_read(short pin, MS_Number<float> &result, double timeout = 10e-3);	
extern void tmu_get_bit(short pin, MS_Number<bool> &result);


extern void oal_set_compensation(short pin, MS_Number<int> PoleStab, MS_Number<int> ZeroStab);
extern void oal_set_compensation(short pin_list, MS_Number<int> *PoleStab_list, MS_Number<int> *ZeroStab_list);
extern void oal_get_compensation(short pin, MS_Number<int> &PoleStab, MS_Number<int> &ZeroStab);
extern void oal_get_compensation(short pin_list, MS_Number<int> *PoleStab_list, MS_Number<int> *ZeroStab_list);
extern void oal_read_ia_offset(short pin, unsigned short ia_range, MS_Number<float> &zero_null, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern void oal_read_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *zero_null_list, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern int oal_cal_ia_offset(short pin, unsigned short ia_range, MS_Number<float> &zero_null, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);
extern int oal_cal_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *zero_null_list, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);
extern void oal_set_ia_offset(short pin, unsigned short ia_range, MS_Number<float> ia_offset);
extern void oal_set_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *ia_offset);


extern void ac_measure(short pin, MS_Number<float> &result ,short ave_num=1, short rms_range=ACS_1V_RMS_RANGE, short coupling=ACS_AC_COUPLING, short wait_us=200);


extern void ddd_get_vih(short pin_list, MS_Number<float> *vih_list);
extern void ddd_get_vih(short pin, MS_Number<float> &vih);
extern void ddd_get_vil(short pin_list, MS_Number<float> *vil_list);
extern void ddd_get_vil(short pin, MS_Number<float> &vil);
extern void ddd_get_vref(short pin_list, MS_Number<float> *vref_list);
extern void ddd_get_vref(short pin, MS_Number<float> &vref);
extern void ddd_get_timings(short pin, MS_Number<float> &tg1, MS_Number<float> &tg2);
extern void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail);
extern void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail);
extern void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail, MS_Number<int> &first_fail_address);
extern void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail, MS_Number<int> &first_fail_address);


extern void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail, MS_Number<int> &first_fail_address, MS_Number<int> &first_fail_pin, char *entry_label=NULL, char *exit_label=NULL, int *fail_count=NULL, short pin_name=-1);		
extern void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail, MS_Number<int> &first_fail_address, MS_Number<int> &first_fail_pin, char *entry_label=NULL, char *exit_label=NULL, int *fail_count=NULL, short pin_name=-1);	
extern void ddd_dig_src(short pin_list, char *pattern_name, MS_Number<unsigned long> src_data, char *entry_label, int displacement=0);
extern void ddd_dig_cap(short pin_list, char *pattern_name, MS_Number<unsigned long> &cap_data, char *entry_label, int displacement=0);


#ifndef	LegacyXerxes




extern void xvi_read_average(short pin, MS_Number<double> &result);				
extern void xvi_read_average(short pin_list, MS_Number<double> *result_list);	
extern void xvi_read_capture(short pin, MSDOUBLE_WF &xvi_capture);				
extern void xvi_read_capture(short pin, MSFLOAT_WF &xvi_capture);				


#ifdef AFX_SDSP_H_INCLUDED


extern CSC_STATUS xvi_read_capture(short pin, int site, Csdsp *sdsp_ptr, WF & s_wave, char * wf_name, const int & data_type=WF_RRECT);	

#endif	

#endif	LegacyXerxes

extern void zap_word_select_lzb(MS_Number<float> trim_value, MS_Number<unsigned int> &zap_word, float *weight_list, unsigned int *word_list, int list_lenght, MS_Number<unsigned int> &idx=MS_Number<unsigned int>(-1));
extern void zap_word_select_lzb(MS_Number<double> trim_value, MS_Number<unsigned int> &zap_word, float *weight_list, unsigned int *word_list, int list_lenght, MS_Number<unsigned int> &idx=MS_Number<unsigned int>(-1));
void store_site_status(SITE_STATUS &usr_active_site);
void store_site_status(MSBOOL &usr_active_site);
void restore_site_status(SITE_STATUS usr_active_site);
void restore_site_status(MSBOOL usr_active_site);

extern	sint	IfBlockCondSiteBuffer;
extern	sint	IfBlockSiteBuffer[];
extern	int		IfBlockStackIdx;
#define ifms(COND) {\
	(COND).copy_to(IfBlockCondSiteBuffer);\
	store_site_status(IfBlockSiteBuffer[IfBlockStackIdx++]);\
	if(IfBlockStackIdx>255)	MessageBox(NULL,"ifms exeeded maximum nesting of 255 levels!","Error!",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);\
	restore_site_status(IfBlockCondSiteBuffer);\
	if(!no_site_active()){
#define endifms }restore_site_status(IfBlockSiteBuffer[--IfBlockStackIdx]);\
	for(int i=0; i<CSC_LAST_SITE; i++) IfBlockSiteBuffer[IfBlockStackIdx][i] = 0;}



#endif

#endif 