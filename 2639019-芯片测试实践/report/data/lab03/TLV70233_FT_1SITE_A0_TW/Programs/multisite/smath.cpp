



























#include ".\programs\multisite\sMath.h"

template <class varType>
void s_set_to_ (varType *variable, varType value)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		variable[site] = value;
}
void s_set_to (sfloat variable, float value) {s_set_to_ <float>(variable, value);}
void s_set_to (sdouble variable, double value) {s_set_to_ <double>(variable, value);}
void s_set_to (sushort variable, unsigned short value) {s_set_to_ <unsigned short>(variable, value);}
void s_set_to (sulong variable, unsigned long value) {s_set_to_ <unsigned long>(variable, value);}
void s_set_to (suint variable, unsigned int value) {s_set_to_ <unsigned int>(variable, value);}
void s_set_to (sint variable, int value) {s_set_to_ <int>(variable, value);}
void s_set_to (sbool variable, int value)  {s_set_to_ <bool>(variable, value);}
void s_set_to (char * variable, char value)  {s_set_to_ <char>(variable, value);}

template <class varType>
void s_wf_set_to_ (varType **variable, varType value, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			variable[site][i] = value;
}
void s_set_to (sfloat_wf variable, float value, unsigned int size) {s_wf_set_to_ <float>(variable, value, size);}
void s_set_to (sdouble_wf variable, double value, unsigned int size) {s_wf_set_to_ <double>(variable, value, size);}

template <class varType>
void s_wf_set_to_s_ (varType **variable, varType *s_value, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			variable[site][i] = s_value[site];
}
void s_set_to (sfloat_wf variable, sfloat s_value, unsigned int size) {s_wf_set_to_s_ <float>(variable, s_value, size);}
void s_set_to (sdouble_wf variable, sdouble s_value, unsigned int size) {s_wf_set_to_s_ <double>(variable, s_value, size);}




template <class varType>
void s_copy_to_(varType *var1, varType *var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		var2[site] = var1[site];
}
void s_copy_to (sfloat var1, sfloat var2) {s_copy_to_ <float>(var1, var2);}
void s_copy_to (sdouble var1, sdouble var2) {s_copy_to_ <double>(var1, var2);}
void s_copy_to (sushort var1, sushort var2) {s_copy_to_ <unsigned short>(var1, var2);}
void s_copy_to (sulong var1, sulong var2) {s_copy_to_ <unsigned long>(var1, var2);}
void s_copy_to (suint var1, suint var2) {s_copy_to_ <unsigned int>(var1, var2);}
void s_copy_to (sint var1, sint var2) {s_copy_to_ <int>(var1, var2);}
void s_copy_to (sbool var1, sbool var2) {s_copy_to_ <bool>(var1, var2);}
void s_copy_to (char * var1, char * var2) {s_copy_to_ <char>(var1, var2);}

template <class varType>
void s_wf_copy_to_ (varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			var2[site][i] = var1[site][i];
}
void s_copy_to (sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_copy_to_ <float>(var1, var2, size);}
void s_copy_to (sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_copy_to_ <double>(var1, var2, size);}




template <class varType>
void s_set_to_fabs_(varType *variable)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		if(variable[site]<0) variable[site]*=(varType)(-1);
}
void s_set_to_fabs (sfloat variable) {s_set_to_fabs_ <float>(variable);}
void s_set_to_fabs (sdouble variable) {s_set_to_fabs_ <double>(variable);}
void s_set_to_fabs (sint variable) {s_set_to_fabs_ <int>(variable);}

template <class varType>
void s_wf_set_to_fabs_ (varType **variable, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			if(variable[site][i]<0) variable[site][i]*=(varType)(-1);
}
void s_set_to_fabs (sfloat_wf variable, unsigned int size) {s_wf_set_to_fabs_ <float>(variable, size);}
void s_set_to_fabs (sdouble_wf variable, unsigned int size) {s_wf_set_to_fabs_ <double>(variable, size);}




template <class varType>
void s_subtract_(varType *result, varType *var1, varType *var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = var1[site] - var2[site];
}
void s_subtract (sfloat result, sfloat var1, sfloat var2) {s_subtract_ <float>(result, var1, var2);}
void s_subtract (sdouble result, sdouble var1, sdouble var2) {s_subtract_ <double>(result, var1, var2);}
void s_subtract (sushort result, sushort var1, sushort var2) {s_subtract_ <unsigned short>(result, var1, var2);}
void s_subtract (sulong result, sulong var1, sulong var2) {s_subtract_ <unsigned long>(result, var1, var2);}
void s_subtract (suint result, suint var1, suint var2) {s_subtract_ <unsigned int>(result, var1, var2);}
void s_subtract (sint result, sint var1, sint var2) {s_subtract_ <int>(result, var1, var2);}

template <class varType>
void s_wf_subtract_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] - var2[site][i];
}
void s_subtract (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_subtract_ <float>(result, var1, var2, size);}
void s_subtract (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_subtract_ <double>(result, var1, var2, size);}




template <class varType>
void s_add_(varType *result, varType *var1, varType *var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = var1[site] + var2[site];
}
void s_add (sfloat result, sfloat var1, sfloat var2) {s_add_ <float>(result, var1, var2);}
void s_add (sdouble result, sdouble var1, sdouble var2) {s_add_ <double>(result, var1, var2);}
void s_add (sushort result, sushort var1, sushort var2) {s_add_ <unsigned short>(result, var1, var2);}
void s_add (sulong result, sulong var1, sulong var2) {s_add_ <unsigned long>(result, var1, var2);}
void s_add (suint result, suint var1, suint var2) {s_add_ <unsigned int>(result, var1, var2);}
void s_add (sint result, sint var1, sint var2) {s_add_ <int>(result, var1, var2);}

template <class varType>
void s_wf_add_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] + var2[site][i];
}
void s_add (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_add_ <float>(result, var1, var2, size);}
void s_add (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_add_ <double>(result, var1, var2, size);}




template <class varType>
void s_scale_(varType *result, varType *var1, varType var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		result[site] = var1[site] * var2;
}
void s_scale (sfloat result, sfloat var1, float var2) {s_scale_ <float>(result, var1, var2);}
void s_scale (sdouble result, sdouble var1, double var2) {s_scale_ <double>(result, var1, var2);}
void s_scale (sushort result, sushort var1, unsigned short var2) {s_scale_ <unsigned short>(result, var1, var2);}
void s_scale (sulong result, sulong var1, unsigned long var2) {s_scale_ <unsigned long>(result, var1, var2);}
void s_scale (suint result, suint var1, unsigned int var2) {s_scale_ <unsigned int>(result, var1, var2);}
void s_scale (sint result, sint var1, int var2) {s_scale_ <int>(result, var1, var2);}

template <class varType>
void s_wf_scale_ (varType **result, varType **var1, varType var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] * var2;
}
void s_scale (sfloat_wf result, sfloat_wf var1, float var2, unsigned int size) {s_wf_scale_ <float>(result, var1, var2, size);}
void s_scale (sdouble_wf result, sdouble_wf var1, double var2, unsigned int size) {s_wf_scale_ <double>(result, var1, var2, size);}




template <class varType>
void s_offset_(varType *result, varType *var1, varType var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = var1[site] + var2;
}
void s_offset (sfloat result, sfloat var1, float var2) {s_offset_ <float>(result, var1, var2);}
void s_offset (sdouble result, sdouble var1, double var2) {s_offset_ <double>(result, var1, var2);}
void s_offset (sushort result, sushort var1, unsigned short var2) {s_offset_ <unsigned short>(result, var1, var2);}
void s_offset (sulong result, sulong var1, unsigned long var2) {s_offset_ <unsigned long>(result, var1, var2);}
void s_offset (suint result, suint var1, unsigned int var2) {s_offset_ <unsigned int>(result, var1, var2);}
void s_offset (sint result, sint var1, int var2) {s_offset_ <int>(result, var1, var2);}

template <class varType>
void s_wf_offset_ (varType **result, varType **var1, varType var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] + var2;
}
void s_offset (sfloat_wf result, sfloat_wf var1, float var2, unsigned int size) {s_wf_offset_ <float>(result, var1, var2, size);}
void s_offset (sdouble_wf result, sdouble_wf var1, double var2, unsigned int size) {s_wf_offset_ <double>(result, var1, var2, size);}




template <class varType>
void s_multiply_(varType *result, varType *var1, varType *var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = var1[site] * var2[site];
}
void s_multiply (sfloat result, sfloat var1, sfloat var2) {s_multiply_ <float>(result, var1, var2);}
void s_multiply (sdouble result, sdouble var1, sdouble var2) {s_multiply_ <double>(result, var1, var2);}
void s_multiply (sushort result, sushort var1, sushort var2) {s_multiply_ <unsigned short>(result, var1, var2);}
void s_multiply (sulong result, sulong var1, sulong var2) {s_multiply_ <unsigned long>(result, var1, var2);}
void s_multiply (suint result, suint var1, suint var2) {s_multiply_ <unsigned int>(result, var1, var2);}
void s_multiply (sint result, sint var1, sint var2) {s_multiply_ <int>(result, var1, var2);}

template <class varType>
void s_wf_multiply_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] * var2[site][i];
}
void s_multiply (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_multiply_ <float>(result, var1, var2, size);}
void s_multiply (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_multiply_ <double>(result, var1, var2, size);}




template <class varType>
void s_divide_(varType *result, varType *var1, varType *var2) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = var1[site] / var2[site];
}
void s_divide (sfloat result, sfloat var1, sfloat var2) {s_divide_ <float>(result, var1, var2);}
void s_divide (sdouble result, sdouble var1, sdouble var2) {s_divide_ <double>(result, var1, var2);}
void s_divide (sushort result, sushort var1, sushort var2) {s_divide_ <unsigned short>(result, var1, var2);}
void s_divide (sulong result, sulong var1, sulong var2) {s_divide_ <unsigned long>(result, var1, var2);}
void s_divide (suint result, suint var1, suint var2) {s_divide_ <unsigned int>(result, var1, var2);}
void s_divide (sint result, sint var1, sint var2) {s_divide_ <int>(result, var1, var2);}

template <class varType>
void s_wf_divide_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = var1[site][i] / var2[site][i];
}
void s_divide (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_divide_ <float>(result, var1, var2, size);}
void s_divide (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_divide_ <double>(result, var1, var2, size);}




template <class varType>
void s_invert_(varType *result, varType *var1)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = -var1[site];
}
void s_invert (sfloat result, sfloat var1) {s_invert_ <float>(result, var1);}
void s_invert (sdouble result, sdouble var1) {s_invert_ <double>(result, var1);}
void s_invert (sint result, sint var1) {s_invert_ <int>(result, var1);}

template <class varType>
void s_wf_invert_ (varType **result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = -var1[site][i];
}
void s_invert (sfloat_wf result, sfloat_wf var1, unsigned int size) {s_wf_invert_ <float>(result, var1, size);}
void s_invert (sdouble_wf result, sdouble_wf var1, unsigned int size) {s_wf_invert_ <double>(result, var1, size);}



template <class varType>
void s_reciprocal_(varType *result, varType *var1)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if(var1[site]!=0.0f)
			result[site] = 1/var1[site];
		else
			result[site]=NULL;
	}
}
void s_reciprocal (sfloat result, sfloat var1) {s_reciprocal_ <float>(result, var1);}
void s_reciprocal (sdouble result, sdouble var1) {s_reciprocal_ <double>(result, var1);}

template <class varType>
void s_wf_reciprocal_ (varType **result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]!=0.0f)
				result[site][i] = 1/var1[site][i];
			else
				result[site][i]=NULL;
		}
}
void s_reciprocal (sfloat_wf result, sfloat_wf var1, unsigned int size) {s_wf_reciprocal_ <float>(result, var1, size);}
void s_reciprocal (sdouble_wf result, sdouble_wf var1, unsigned int size) {s_wf_reciprocal_ <double>(result, var1, size);}




template <class varType>
void s_pow_(varType *result, varType *var1, varType value) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		result[site] = (varType)pow((double)var1[site],(double)value);
}
void s_pow (sfloat result, sfloat var1, float value) {s_pow_ <float>(result, var1, value);}
void s_pow (sdouble result, sdouble var1, double value) {s_pow_ <double>(result, var1, value);}

template <class varType>
void s_wf_pow_ (varType **result, varType **var1, varType value, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
			result[site][i] = (varType)pow((double)var1[site][i],(double)value);
}
void s_pow (sfloat_wf result, sfloat_wf var1, float value, unsigned int size) {s_wf_pow_ <float>(result, var1, value, size);}
void s_pow (sdouble_wf result, sdouble_wf var1, double value, unsigned int size) {s_wf_pow_ <double>(result, var1, value, size);}




template <class varType>
void s_log_(varType *result, varType *var1) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if(var1[site]>0.0f)
			result[site] = log(var1[site]);
		else
			result[site]=NULL;
	}
}
void s_log (sfloat result, sfloat var1) {s_log_ <float>(result, var1);}
void s_log (sdouble result, sdouble var1) {s_log_ <double>(result, var1);}

template <class varType>
void s_wf_log_ (varType **result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]>0.0f)
				result[site][i] = log(var1[site][i]);
			else
				result[site][i]=NULL;
		}
}
void s_log (sfloat_wf result, sfloat_wf var1, unsigned int size) {s_wf_log_ <float>(result, var1, size);}
void s_log (sdouble_wf result, sdouble_wf var1, unsigned int size) {s_wf_log_ <double>(result, var1, size);}




template <class varType>
void s_log10_(varType *result, varType *var1) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if(var1[site]>0.0f)
			result[site] = log10(var1[site]);
		else
			result[site]=NULL;
	}
}
void s_log10 (sfloat result, sfloat var1) {s_log10_ <float>(result, var1);}
void s_log10 (sdouble result, sdouble var1) {s_log10_ <double>(result, var1);}

template <class varType>
void s_wf_log10_ (varType **result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]>0.0f)
				result[site][i] = log10(var1[site][i]);
			else
				result[site][i]=NULL;
		}
}
void s_log10 (sfloat_wf result, sfloat_wf var1, unsigned int size) {s_wf_log10_ <float>(result, var1, size);}
void s_log10 (sdouble_wf result, sdouble_wf var1, unsigned int size) {s_wf_log10_ <double>(result, var1, size);}




template <class varType>
void s_log2_(varType *result, varType *var1) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if(var1[site]>0.0f)
			result[site] = log(var1[site])/log(2.0);
		else
			result[site]=NULL;
	}
}
void s_log2 (sfloat result, sfloat var1) {s_log2_ <float>(result, var1);}
void s_log2 (sdouble result, sdouble var1) {s_log2_ <double>(result, var1);}

template <class varType>
void s_wf_log2_ (varType **result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]>0.0f)
				result[site][i] = log(var1[site][i])/log(2.0);
			else
				result[site][i]=NULL;
		}
}
void s_log2 (sfloat_wf result, sfloat_wf var1, unsigned int size) {s_wf_log2_ <float>(result, var1, size);}
void s_log2 (sdouble_wf result, sdouble_wf var1, unsigned int size) {s_wf_log2_ <double>(result, var1, size);}




template <class varType>
void s_db_(varType *result, varType *var1, varType *var2) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if((var1[site]!=0.0f)&&(var1[site]!=0.0f))
			result[site] = 10*log10(fabs(var1[site]/var2[site]));
		else
			result[site]=NULL;
	}
}
void s_db (sfloat result, sfloat var1, sfloat var2) {s_db_ <float>(result, var1, var2);}
void s_db (sdouble result, sdouble var1, sdouble var2) {s_db_ <double>(result, var1, var2);}

template <class varType>
void s_wf_db_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]>0.0f)
				result[site][i] = 10*log10(fabs(var1[site][i]/var2[site][i]));
			else
				result[site][i]=NULL;
		}
}
void s_db (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_db_ <float>(result, var1, var2, size);}
void s_db (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_db_ <double>(result, var1, var2, size);}




template <class varType>
void s_mag_db_(varType *result, varType *var1, varType *var2) 
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if((var1[site]>0.0f)&&(var1[site]>0.0f))
			result[site] = 20*log10(fabs(var1[site]/var2[site]));
		else
			result[site]=NULL;
	}
}
void s_mag_db (sfloat result, sfloat var1, sfloat var2) {s_mag_db_ <float>(result, var1, var2);}
void s_mag_db (sdouble result, sdouble var1, sdouble var2) {s_mag_db_ <double>(result, var1, var2);}

template <class varType>
void s_wf_mag_db_ (varType **result, varType **var1, varType **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		for(unsigned int i=0; i<size; i++)
		{
			if(var1[site][i]>0.0f)
				result[site][i] = 10*log10(fabs(var1[site][i]/var2[site][i]));
			else
				result[site][i]=NULL;
		}
}
void s_mag_db (sfloat_wf result, sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_mag_db_ <float>(result, var1, var2, size);}
void s_mag_db (sdouble_wf result, sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_mag_db_ <double>(result, var1, var2, size);}




template <class varType1, class varType2>
void s_copy_(varType1 *var1, varType2 *var2)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		var1[site] = (varType1)var2[site];
}
void s_copy (sfloat var1, sfloat var2) {s_copy_ <float, float>(var1, var2);}
void s_copy (sfloat var1, sdouble var2) {s_copy_ <float, double>(var1, var2);}
void s_copy (sfloat var1, sushort var2) {s_copy_ <float, unsigned short>(var1, var2);}
void s_copy (sfloat var1, sulong var2) {s_copy_ <float, unsigned long>(var1, var2);}
void s_copy (sfloat var1, suint var2) {s_copy_ <float, unsigned int>(var1, var2);}
void s_copy (sfloat var1, sint var2) {s_copy_ <float, int>(var1, var2);}
void s_copy (sfloat var1, sbool var2) {s_copy_ <float, bool>(var1, var2);}

void s_copy (sdouble var1, sfloat var2) {s_copy_ <double, float>(var1, var2);}
void s_copy (sdouble var1, sdouble var2) {s_copy_ <double, double>(var1, var2);}
void s_copy (sdouble var1, sushort var2) {s_copy_ <double, unsigned short>(var1, var2);}
void s_copy (sdouble var1, sulong var2) {s_copy_ <double, unsigned long>(var1, var2);}
void s_copy (sdouble var1, suint var2) {s_copy_ <double, unsigned int>(var1, var2);}
void s_copy (sdouble var1, sint var2) {s_copy_ <double, int>(var1, var2);}
void s_copy (sdouble var1, sbool var2) {s_copy_ <double, bool>(var1, var2);}

void s_copy (sushort var1, sfloat var2) {s_copy_ <unsigned short, float>(var1, var2);}
void s_copy (sushort var1, sdouble var2) {s_copy_ <unsigned short, double>(var1, var2);}
void s_copy (sushort var1, sushort var2) {s_copy_ <unsigned short, unsigned short>(var1, var2);}
void s_copy (sushort var1, sulong var2) {s_copy_ <unsigned short, unsigned long>(var1, var2);}
void s_copy (sushort var1, suint var2) {s_copy_ <unsigned short, unsigned int>(var1, var2);}
void s_copy (sushort var1, sint var2) {s_copy_ <unsigned short, int>(var1, var2);}
void s_copy (sushort var1, sbool var2) {s_copy_ <unsigned short, bool>(var1, var2);}

void s_copy (sulong var1, sfloat var2) {s_copy_ <unsigned long, float>(var1, var2);}
void s_copy (sulong var1, sdouble var2) {s_copy_ <unsigned long, double>(var1, var2);}
void s_copy (sulong var1, sushort var2) {s_copy_ <unsigned long, unsigned short>(var1, var2);}
void s_copy (sulong var1, sulong var2) {s_copy_ <unsigned long, unsigned long>(var1, var2);}
void s_copy (sulong var1, suint var2) {s_copy_ <unsigned long, unsigned int>(var1, var2);}
void s_copy (sulong var1, sint var2) {s_copy_ <unsigned long, int>(var1, var2);}
void s_copy (sulong var1, sbool var2) {s_copy_ <unsigned long, bool>(var1, var2);}

void s_copy (suint var1, sfloat var2) {s_copy_ <unsigned int, float>(var1, var2);}
void s_copy (suint var1, sdouble var2) {s_copy_ <unsigned int, double>(var1, var2);}
void s_copy (suint var1, sushort var2) {s_copy_ <unsigned int, unsigned short>(var1, var2);}
void s_copy (suint var1, sulong var2) {s_copy_ <unsigned int, unsigned long>(var1, var2);}
void s_copy (suint var1, suint var2) {s_copy_ <unsigned int, unsigned int>(var1, var2);}
void s_copy (suint var1, sint var2) {s_copy_ <unsigned int, int>(var1, var2);}
void s_copy (suint var1, sbool var2) {s_copy_ <unsigned int, bool>(var1, var2);}

void s_copy (sint var1, sfloat var2) {s_copy_ <int, float>(var1, var2);}
void s_copy (sint var1, sdouble var2) {s_copy_ <int, double>(var1, var2);}
void s_copy (sint var1, sushort var2) {s_copy_ <int, unsigned short>(var1, var2);}
void s_copy (sint var1, sulong var2) {s_copy_ <int, unsigned long>(var1, var2);}
void s_copy (sint var1, suint var2) {s_copy_ <int, unsigned int>(var1, var2);}
void s_copy (sint var1, sint var2) {s_copy_ <int, int>(var1, var2);}
void s_copy (sint var1, sbool var2) {s_copy_ <int, bool>(var1, var2);}

void s_copy (sbool var1, sfloat var2) {s_copy_ <bool, float>(var1, var2);}
void s_copy (sbool var1, sdouble var2) {s_copy_ <bool, double>(var1, var2);}
void s_copy (sbool var1, sushort var2) {s_copy_ <bool, unsigned short>(var1, var2);}
void s_copy (sbool var1, sulong var2) {s_copy_ <bool, unsigned long>(var1, var2);}
void s_copy (sbool var1, suint var2) {s_copy_ <bool, unsigned int>(var1, var2);}
void s_copy (sbool var1, sint var2) {s_copy_ <bool, int>(var1, var2);}
void s_copy (sbool var1, sbool var2) {s_copy_ <bool, bool>(var1, var2);}

template <class varType1, class varType2>
void s_wf_copy_(varType1 **var1, varType2 **var2, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
		for(unsigned int i=0; i<size; i++)
			var1[site][i] = (varType1)var2[site][i];
}

void s_copy (sfloat_wf var1, sfloat_wf var2, unsigned int size) {s_wf_copy_ <float, float>(var1, var2, size);}
void s_copy (sfloat_wf var1, sdouble_wf var2, unsigned int size) {s_wf_copy_ <float, double>(var1, var2, size);}
void s_copy (sdouble_wf var1, sfloat_wf var2, unsigned int size) {s_wf_copy_ <double, float>(var1, var2, size);}
void s_copy (sdouble_wf var1, sdouble_wf var2, unsigned int size) {s_wf_copy_ <double, double>(var1, var2, size);}




void s_calc_R(float *variable, float voltage_current, short meas_V_I)
{
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])
	{
		if (variable[site] == 0)
			variable[site] = 0;
		else
			if (meas_V_I == MEASURE_CURRENT)
				variable[site] = voltage_current/variable[site];
			else	
				variable[site] = variable[site]/voltage_current;
	}
}



template <class varType1, class varType2>
int s_compare_(varType1 *variable, varType2 value, char oper)
{
	int res=1;

	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
		switch (oper)
		{
			case '>': if (variable[site]<=value) res=0; break;
			case '<': if (variable[site]>=value) res=0; break;
			case '=': if (variable[site]!=value) res=0; break;
			default: res=-1; printf("s_compare: error! non valid operator!\n");
		}
	return res;
}

int s_compare(sfloat var1, float var2, char oper) {return s_compare_ <float>(var1, var2, oper);}
int s_compare(sdouble var1, double var2, char oper) {return s_compare_ <double>(var1, var2, oper);}
int s_compare(sushort var1, unsigned short var2, char oper) {return s_compare_ <unsigned short>(var1, var2, oper);}
int s_compare(sulong var1, unsigned long var2, char oper) {return s_compare_ <unsigned long>(var1, var2, oper);}
int s_compare(suint var1, unsigned int var2, char oper) {return s_compare_ <unsigned int>(var1, var2, oper);}
int s_compare(sint var1, int var2, char oper) {return s_compare_ <int>(var1, var2, oper);}
int s_compare(sbool var1, bool var2, char oper) {return s_compare_ <bool>(var1, var2, oper);}
int s_compare(char *var1, char var2, char oper) {return s_compare_ <char>(var1, var2, oper);}




template <class varType>
void s_wf_average_ (varType *result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
	{
		result[site]=0;
		for(unsigned int i=0; i<size; i++)
			result[site] += var1[site][i];
		result[site]/=size;
	}
}
void s_average (sfloat result, sfloat_wf var1, unsigned int size) {s_wf_average_ <float>(result, var1, size);}
void s_average (sdouble result, sdouble_wf var1, unsigned int size) {s_wf_average_ <double>(result, var1, size);}




template <class varType>
void s_wf_rms_ (varType *result, varType **var1, unsigned int size)
{
	if(size>0)
	for(int site=0; site < CSC_LAST_SITE; site++) if (active_site[site])	
	{
		result[site]=0;
		for(unsigned int i=0; i<size; i++)
			result[site] += (varType)pow((double)var1[site][i],2.0);
		result[site]/=size;
		
		result[site] = (varType)pow((double)result[site],0.5);
	}
}
void s_rms (sfloat result, sfloat_wf var1, unsigned int size) {s_wf_rms_ <float>(result, var1, size);}
void s_rms (sdouble result, sdouble_wf var1, unsigned int size) {s_wf_rms_ <double>(result, var1, size);}

#ifndef LegacyVATE522
template <class varType>
MS_Number<double> MS_Number<varType>::math_func(double (*pf)(double))
{
	int site=0;
	MS_Number<double> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,(double)((*pf)((double)ms_value[site])));
	
	return ret;
}

template <class varType>
MS_Number<double> MS_Number<varType>::math_func2(double (*pf)(double, double),MS_Number<varType> MS_Num2)
{
	int site=0;
	MS_Number<double> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,(double)((*pf)((double)ms_value[site],(double)MS_Num2.get_value(site))));
	
	return ret;
}

template <class varType>
MS_Number<varType>::MS_Number()
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	

	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;



	ms_value=new varType[last_site];	


	for (site=0; site < last_site; site++)	
		ms_value[site]=0;
}

template <class varType>
MS_Number<varType>::~MS_Number()
{
	delete ms_value;
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<double>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	

	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<float>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<int>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}


template <class varType>
MS_Number<varType>::MS_Number(MS_Number<short>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)MS_Num.get_value(site);
		else
		ms_value[site]=0;
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<long>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)MS_Num.get_value(site);
		else
		ms_value[site]=0;
}


template <class varType>
MS_Number<varType>::MS_Number(MS_Number<unsigned int>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<unsigned short>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<unsigned long>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(MS_Number<bool>& MS_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)MS_Num.get_value(site);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(sDouble &s_Num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	ms_id=MS_DOUBLE;
	

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_Num[site]);
}

template <class varType>
MS_Number<varType>::MS_Number(double *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(float *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(int *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}



template <class varType>
MS_Number<varType>::MS_Number(short *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)(s_num[site]);
		else
		ms_value[site]=0;
}

template <class varType>
MS_Number<varType>::MS_Number(long *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)(s_num[site]);
		else
		ms_value[site]=0;
}


template <class varType>
MS_Number<varType>::MS_Number(unsigned int *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(unsigned short *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(unsigned long *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(bool *s_num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;


	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(s_num[site]);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(double num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	

	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(float num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(int num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}


template <class varType>
MS_Number<varType>::MS_Number(short num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)(num);
		else
		ms_value[site]=0;
}

template <class varType>
MS_Number<varType>::MS_Number(long num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_value=new varType[last_site];
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)(num);
		else
		ms_value[site]=0;
}


template <class varType>
MS_Number<varType>::MS_Number(unsigned int num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(unsigned short num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(unsigned long num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
MS_Number<varType>::MS_Number(bool num)
{
	int site		= 0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);	
	
	
	ms_value=new varType[last_site];	
	
	if(typeid(varType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(varType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(varType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(varType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(varType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(varType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(varType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(varType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(varType)==typeid(bool))			ms_id=MS_BOOL;

	
	for (site=0; site < last_site; site++) if(IS_SITE_ACTIVE)		
		ms_value[site]=(varType)(num);
		
		else
		ms_value[site]=0;
		
}

template <class varType>
void MS_Number<varType>::copy_to(sDouble &s_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_Num[site]=(double)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(float *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(float)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(double *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(double)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(int *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(int)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(unsigned int *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(unsigned int)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(unsigned short *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(unsigned short)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(unsigned long *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(unsigned long)(ms_value[site]);
}

template <class varType>
void MS_Number<varType>::copy_to(bool *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		s_num[site]=(bool)(ms_value[site]);
}

template <class varType>
varType & MS_Number<varType>::operator[](int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

template <class varType>
varType & MS_Number<varType>::operator()(int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator= (const MS_Number<varType>& MS_Num)
{
	int site=0;
	if(this==&MS_Num)
		return *this;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ms_value[site]=(varType)MS_Num.ms_value[site];
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator+ (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,ms_value[site]+MS_Num.get_value(site));
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator- (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,ms_value[site]-MS_Num.get_value(site));
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator* (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,ms_value[site]*MS_Num.get_value(site));
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator/ (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,ms_value[site]/MS_Num.get_value(site));
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator% (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator % applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSSHORT, MSUSHORT, MSLONG, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]%(unsigned long)(MS_Num.get_value(site))));
		break;
	}
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator+= (MS_Number<varType> MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ms_value[site]+=MS_Num.get_value(site);
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator-= (MS_Number<varType> MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ms_value[site]-=MS_Num.get_value(site);
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator*= (MS_Number<varType> MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ms_value[site]*=MS_Num.get_value(site);
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator/= (MS_Number<varType> MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ms_value[site]/=MS_Num.get_value(site);
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator%= (MS_Number<varType> MS_Num)
{
	int site=0;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator %= applies to MSINT, MSSHORT, MSUSHORT MSSHORT, MSUSHORT, MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ms_value[site]=(varType)((unsigned long)ms_value[site]%(unsigned long)(MS_Num.get_value(site)));
		break;
	}
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator>> (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator >> applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]>>(unsigned long)(MS_Num.get_value(site))));
		break;
	}
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator<< (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator << applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]<<(unsigned long)(MS_Num.get_value(site))));
		break;
	}
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator>>= (MS_Number<varType> MS_Num)
{
	int site=0;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator >>= applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ms_value[site]=(varType)((unsigned long)ms_value[site]>>(unsigned long)(MS_Num.get_value(site)));
		break;
	}
	
	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator<<= (MS_Number<varType> MS_Num)
{
	int site=0;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator <<= applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ms_value[site]=(varType)((unsigned long)ms_value[site]<<(unsigned long)(MS_Num.get_value(site)));
		break;
	}
	
	return *this;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator== (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]==MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator!= (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]!=MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator> (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]>MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator< (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]<MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator>= (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]>=MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator<= (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]<=MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::operator!()
{
	int site=0;
	MS_Number<bool> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator ! applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)(!(unsigned long)(ms_value[site])));
		break;
	}
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator&& (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]&&MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator|| (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(ms_value[site]||MS_Num.get_value(site))
			ret.set_value(site,true);
		else
			ret.set_value(site,false);
	}
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator~()
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator ~ applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)(~(unsigned long)(ms_value[site])));
		break;
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)(ms_value[site] ? false : true));
		break;
	}
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator& (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator & applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]&(unsigned long)(MS_Num.get_value(site))));
		break;
	}
	
	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator| (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator | applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]|(unsigned long)(MS_Num.get_value(site))));
		break;
	}

	return ret;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::operator^ (MS_Number<varType> MS_Num)
{
	int site=0;
	MS_Number<varType> ret;

	switch(ms_id)
	{
	case MS_DOUBLE:
	case MS_FLOAT:
		MessageBox(NULL,"Operator ^ applies to MSINT, MSSHORT, MSUSHORT MSUINT, MSUSHORT, MSULONG, MSBOOL only","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		break;
	case MS_INT:
	case MS_SHORT:	
	case MS_LONG:	
	case MS_SUINT:
	case MS_SUSHORT:
	case MS_SULONG:
	case MS_BOOL:
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			ret.set_value(site,(varType)((unsigned long)ms_value[site]^(unsigned long)(MS_Num.get_value(site))));
		break;
	}

	return ret;
}

template <class varType>
MS_Number<double> MS_Number<varType>::sign()
{
	int site=0;
	MS_Number<double> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		ret.set_value(site,(ms_value[site]<0 ? -1.0 : 1.0));
	
	return ret;
}

template <class varType>
MS_Number<double> MS_Number<varType>::round(unsigned short dec_digits)
{
	int site=0;
	MS_Number<double> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		ret.set_value(site,ms_value[site]);

		if(dec_digits>0)
			ret.set_value(site, ret[site]*pow(10.0,(double)dec_digits));
	
		ret.set_value(site, floor(ret[site]+0.5));
	
		if(dec_digits>0)
			ret.set_value(site, ret[site]*pow(10.0,-(double)dec_digits));
	}
	
	return ret;
}

template <class varType>
varType MS_Number<varType>::get_value(int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

template <class varType>
void MS_Number<varType>::set_value(int site, varType num)
{
	if(site<CSC_LAST_SITE)
		ms_value[site]=(varType)num;
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}
}

template <class varType>
MsNumIdType MS_Number<varType>::get_type()
{
	return ms_id;
}

template <class varType>
void MS_Number<varType>::init(void)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=0;
}

template <class varType>
varType MS_Number<varType>::get_max_site(int *s)	
{
	bool	first_val	= true;
	int		site		= 0;
	varType	max_val		= 0;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
		if((first_val)||(ms_value[site]>max_val))
		{
			max_val=ms_value[site];
			if(s!=NULL)
				*s=site;
			first_val=false;
		}
	return max_val;
}

template <class varType>
varType MS_Number<varType>::get_min_site(int *s)	
{
	bool	first_val	= true;
	int		site		= 0;
	varType	min_val		= 0;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
		if((first_val)||(ms_value[site]<min_val))
		{
			min_val=ms_value[site];
			if(s!=NULL)
				*s=site;
			first_val=false;
		}
	return min_val;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::clip_max(MS_Number<varType> MS_Num)	
{
	int		site		= 0;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
		if(ms_value[site]>MS_Num[site])
			ms_value[site]=MS_Num[site];

	return *this;
}

template <class varType>
MS_Number<varType> MS_Number<varType>::clip_min(MS_Number<varType> MS_Num)	
{
	int		site		= 0;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
		if(ms_value[site]<MS_Num[site])
			ms_value[site]=MS_Num[site];

	return *this;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::is_between(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2, bool include_lims)	
{
	int				site		= 0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
	{
		if(include_lims)
		{
			if((ms_value[site]>=MS_Num1[site])&&(ms_value[site]<=MS_Num2[site]))
				ret[site]=true;
			else
				ret[site]=false;
		}
		else
		{
			if((ms_value[site]>MS_Num1[site])&&(ms_value[site]<MS_Num2[site]))
				ret[site]=true;
			else
				ret[site]=false;
		}
	}

	return ret;
}

template <class varType>
MS_Number<bool> MS_Number<varType>::is_between(varType Num1, varType Num2, bool include_lims)	
{
	int				site		= 0;
	MS_Number<bool> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(active_site[site])
	{
		if(include_lims)
		{
			if((ms_value[site]>=Num1)&&(ms_value[site]<=Num2))
				ret[site]=true;
			else
				ret[site]=false;
		}
		else
		{
			if((ms_value[site]>Num1)&&(ms_value[site]<Num2))
				ret[site]=true;
			else
				ret[site]=false;
		}
	}

	return ret;
}

template class __declspec(dllexport) MS_Number<double>;
template class __declspec(dllexport) MS_Number<float>;
template class __declspec(dllexport) MS_Number<bool>;
template class __declspec(dllexport) MS_Number<int>;
template class __declspec(dllexport) MS_Number<unsigned int>;
template class __declspec(dllexport) MS_Number<unsigned short>;
template class __declspec(dllexport) MS_Number<unsigned long>;

MS_Number<double> acos(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(acos); return ret;}
MS_Number<double> acos(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(acos); return ret;}
MS_Number<double> acos(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(acos); return ret;}
MS_Number<double> acos(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(acos); return ret;}

MS_Number<double> asin(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(asin); return ret;}
MS_Number<double> asin(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(asin); return ret;}
MS_Number<double> asin(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(asin); return ret;}
MS_Number<double> asin(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(asin); return ret;}

MS_Number<double> atan(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(atan); return ret;}
MS_Number<double> atan(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(atan); return ret;}
MS_Number<double> atan(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(atan); return ret;}
MS_Number<double> atan(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(atan); return ret;}

MS_Number<double> ceil(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(ceil); return ret;}
MS_Number<double> ceil(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(ceil); return ret;}
MS_Number<double> ceil(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(ceil); return ret;}
MS_Number<double> ceil(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(ceil); return ret;}

MS_Number<double> cos(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(cos); return ret;}
MS_Number<double> cos(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(cos); return ret;}
MS_Number<double> cos(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(cos); return ret;}
MS_Number<double> cos(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(cos); return ret;}

MS_Number<double> cosh(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(cosh); return ret;}
MS_Number<double> cosh(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(cosh); return ret;}
MS_Number<double> cosh(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(cosh); return ret;}
MS_Number<double> cosh(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(cosh); return ret;}

MS_Number<double> exp(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(exp); return ret;}
MS_Number<double> exp(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(exp); return ret;}
MS_Number<double> exp(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(exp); return ret;}
MS_Number<double> exp(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(exp); return ret;}

MS_Number<double> exp2(MS_Number<double> MS_Num){MS_Number<double> MS_temp=2.0; MS_Number<double> ret=MS_temp.math_func2(pow, MS_Num); return ret;}
MS_Number<double> exp2(MS_Number<float> MS_Num){MS_Number<double> MS_temp=2.0; MS_Number<double> ret=MS_temp.math_func2(pow, MS_Num); return ret;}
MS_Number<double> exp2(double *s_num){MS_Number<double> MS_temp=2.0; MS_Number<double> ret=MS_temp.math_func2(pow, s_num); return ret;}
MS_Number<double> exp2(float *s_num){MS_Number<double> MS_temp=2.0; MS_Number<double> ret=MS_temp.math_func2(pow, s_num); return ret;}

MS_Number<double> exp10(MS_Number<double> MS_Num){MS_Number<double> MS_temp=10.0; MS_Number<double> ret=MS_temp.math_func2(pow, MS_Num); return ret;}
MS_Number<double> exp10(MS_Number<float> MS_Num){MS_Number<double> MS_temp=10.0; MS_Number<double> ret=MS_temp.math_func2(pow, MS_Num); return ret;}
MS_Number<double> exp10(double *s_num){MS_Number<double> MS_temp=10.0; MS_Number<double> ret=MS_temp.math_func2(pow, s_num); return ret;}
MS_Number<double> exp10(float *s_num){MS_Number<double> MS_temp=10.0; MS_Number<double> ret=MS_temp.math_func2(pow, s_num); return ret;}

MS_Number<double> fabs(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(fabs); return ret;}
MS_Number<double> fabs(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(fabs); return ret;}
MS_Number<double> fabs(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(fabs); return ret;}
MS_Number<double> fabs(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(fabs); return ret;}

MS_Number<double> floor(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(floor); return ret;}
MS_Number<double> floor(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(floor); return ret;}
MS_Number<double> floor(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(floor); return ret;}
MS_Number<double> floor(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(floor); return ret;}

MS_Number<double> log(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(log); return ret;}
MS_Number<double> log(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(log); return ret;}
MS_Number<double> log(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log); return ret;}
MS_Number<double> log(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log); return ret;}

MS_Number<double> log10(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(log10); return ret;}
MS_Number<double> log10(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(log10); return ret;}
MS_Number<double> log10(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log10); return ret;}
MS_Number<double> log10(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log10); return ret;}

MS_Number<double> log2(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(log)/log(2.0); return ret;}
MS_Number<double> log2(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(log)/log(2.0); return ret;}
MS_Number<double> log2(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log)/log(2.0); return ret;}
MS_Number<double> log2(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(log)/log(2.0); return ret;}

MS_Number<double> sin(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(sin); return ret;}
MS_Number<double> sin(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(sin); return ret;}
MS_Number<double> sin(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sin); return ret;}
MS_Number<double> sin(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sin); return ret;}

MS_Number<double> sinh(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(sinh); return ret;}
MS_Number<double> sinh(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(sinh); return ret;}
MS_Number<double> sinh(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sinh); return ret;}
MS_Number<double> sinh(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sinh); return ret;}

MS_Number<double> tan(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(tan); return ret;}
MS_Number<double> tan(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(tan); return ret;}
MS_Number<double> tan(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(tan); return ret;}
MS_Number<double> tan(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(tan); return ret;}

MS_Number<double> tanh(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(tanh); return ret;}
MS_Number<double> tanh(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(tanh); return ret;}
MS_Number<double> tanh(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(tanh); return ret;}
MS_Number<double> tanh(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(tanh); return ret;}

MS_Number<double> sqrt(MS_Number<double> MS_Num){MS_Number<double> ret=MS_Num.math_func(sqrt); return ret;}
MS_Number<double> sqrt(MS_Number<float> MS_Num){MS_Number<double> ret=MS_Num.math_func(sqrt); return ret;}
MS_Number<double> sqrt(double *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sqrt); return ret;}
MS_Number<double> sqrt(float *s_num){MS_Number<double> MS_temp=s_num; MS_Number<double> ret=MS_temp.math_func(sqrt); return ret;}

MS_Number<double> pow(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(pow, MS_Num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(pow, MS_Num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(pow, MS_Num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(pow, MS_Num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, double *s_num2){MS_Number<double> ret=MS_Num1.math_func2(pow, s_num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, double *s_num2){MS_Number<double> ret=MS_Num1.math_func2(pow, s_num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, float *s_num2){MS_Number<double> ret=MS_Num1.math_func2(pow, s_num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, float *s_num2){MS_Number<double> ret=MS_Num1.math_func2(pow, s_num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, double num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, double num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, float num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, float num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}
MS_Number<double> pow(MS_Number<double> MS_Num1, int num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}
MS_Number<double> pow(MS_Number<float> MS_Num1, int num2){MS_Number<double> ret=MS_Num1.math_func2(pow, num2); return ret;}

MS_Number<double> fmod(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, MS_Num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, MS_Num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, MS_Num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, MS_Num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, double *s_num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, s_num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, double *s_num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, s_num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, float *s_num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, s_num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, float *s_num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, s_num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, double num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, double num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, float num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, float num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}
MS_Number<double> fmod(MS_Number<double> MS_Num1, int num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}
MS_Number<double> fmod(MS_Number<float> MS_Num1, int num2){MS_Number<double> ret=MS_Num1.math_func2(fmod, num2); return ret;}

MS_Number<double> sign(MS_Number<double> MS_Num){return MS_Num.sign();};
MS_Number<double> sign(MS_Number<float> MS_Num){return MS_Num.sign();};
MS_Number<double> sign(double *s_num){MS_Number<double> MS_temp=s_num; return MS_temp.sign();};
MS_Number<double> sign(float *s_num){MS_Number<double> MS_temp=s_num; return MS_temp.sign();};

MS_Number<double> round(MS_Number<double> MS_Num, unsigned short dec_digits){return MS_Num.round(dec_digits);};
MS_Number<double> round(MS_Number<float> MS_Num, unsigned short dec_digits){return MS_Num.round(dec_digits);};
MS_Number<double> round(double *s_num, unsigned short dec_digits){MS_Number<double> MS_temp=s_num; return MS_temp.round(dec_digits);};
MS_Number<double> round(float *s_num, unsigned short dec_digits){MS_Number<double> MS_temp=s_num; return MS_temp.round(dec_digits);};

template <class varType>
MS_Number<varType> ms_max(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	int site=0;
	MS_Number<varType> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(MS_Num1.get_value(site)>MS_Num2.get_value(site))
			ret.set_value(site,MS_Num1.get_value(site));
		else
			ret.set_value(site,MS_Num2.get_value(site));
	}
	return ret;
}

MS_Number<double>			fmax(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){return ms_max<double>(MS_Num1, MS_Num2);};
MS_Number<float>			fmax(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){return ms_max<float>(MS_Num1, MS_Num2);};
MS_Number<int>				fmax(MS_Number<int> MS_Num1, MS_Number<int> MS_Num2){return ms_max<int>(MS_Num1, MS_Num2);};
MS_Number<short>			fmax(MS_Number<short> MS_Num1, MS_Number<short> MS_Num2){return ms_max<short>(MS_Num1, MS_Num2);};	
MS_Number<long>				fmax(MS_Number<long> MS_Num1, MS_Number<long> MS_Num2){return ms_max<long>(MS_Num1, MS_Num2);};		
MS_Number<unsigned int>		fmax(MS_Number<unsigned int> MS_Num1, MS_Number<unsigned int> MS_Num2){return ms_max<unsigned int>(MS_Num1, MS_Num2);};
MS_Number<unsigned short>	fmax(MS_Number<unsigned short> MS_Num1, MS_Number<unsigned short> MS_Num2){return ms_max<unsigned short>(MS_Num1, MS_Num2);};
MS_Number<unsigned long>	fmax(MS_Number<unsigned long> MS_Num1, MS_Number<unsigned long> MS_Num2){return ms_max<unsigned long>(MS_Num1, MS_Num2);};

template <class varType>
MS_Number<varType> ms_min(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	int site=0;
	MS_Number<double> ret;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{
		if(MS_Num1.get_value(site)<MS_Num2.get_value(site))
			ret.set_value(site,MS_Num1.get_value(site));
		else
			ret.set_value(site,MS_Num2.get_value(site));
	}
	return ret;
}

MS_Number<double>			fmin(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){return ms_min<double>(MS_Num1, MS_Num2);};
MS_Number<float>			fmin(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){return ms_min<float>(MS_Num1, MS_Num2);};
MS_Number<int>				fmin(MS_Number<int> MS_Num1, MS_Number<int> MS_Num2){return ms_min<int>(MS_Num1, MS_Num2);};
MS_Number<short>			fmin(MS_Number<short> MS_Num1, MS_Number<short> MS_Num2){return ms_min<short>(MS_Num1, MS_Num2);};	
MS_Number<long>				fmin(MS_Number<long> MS_Num1, MS_Number<long> MS_Num2){return ms_min<long>(MS_Num1, MS_Num2);};		
MS_Number<unsigned int>		fmin(MS_Number<unsigned int> MS_Num1, MS_Number<unsigned int> MS_Num2){return ms_min<unsigned int>(MS_Num1, MS_Num2);};
MS_Number<unsigned short>	fmin(MS_Number<unsigned short> MS_Num1, MS_Number<unsigned short> MS_Num2){return ms_min<unsigned short>(MS_Num1, MS_Num2);};
MS_Number<unsigned long>	fmin(MS_Number<unsigned long> MS_Num1, MS_Number<unsigned long> MS_Num2){return ms_min<unsigned long>(MS_Num1, MS_Num2);};

template <class varType>
MS_Number<double> ms_db(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	MS_Number<double> ret=MS_Num1.math_func(fabs);

	ret=ret/MS_Num2.math_func(fabs);
	ret=ret.math_func(log)*10.0;
	
	return ret;
}

MS_Number<double> db(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){return ms_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> db(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2){return ms_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> db(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2){return ms_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> db(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){return ms_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> db(double *s_num1, double *s_num2){return ms_db<double>(s_num1, s_num2);};
MS_Number<double> db(float *s_num1, float *s_num2){return ms_db<double>(s_num1, s_num2);};

template <class varType>
MS_Number<double> ms_mag_db(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	MS_Number<double> ret=MS_Num1.math_func(fabs);

	ret=ret/MS_Num2.math_func(fabs);
	ret=ret.math_func(log)*20.0;
	
	return ret;
}

MS_Number<double> mag_db(MS_Number<double> MS_Num1, MS_Number<double> MS_Num2){return ms_mag_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> mag_db(MS_Number<float> MS_Num1, MS_Number<double> MS_Num2){return ms_mag_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> mag_db(MS_Number<double> MS_Num1, MS_Number<float> MS_Num2){return ms_mag_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> mag_db(MS_Number<float> MS_Num1, MS_Number<float> MS_Num2){return ms_mag_db<double>(MS_Num1, MS_Num2);};
MS_Number<double> mag_db(double *s_num1, double *s_num2){return ms_mag_db<double>(s_num1, s_num2);};
MS_Number<double> mag_db(float *s_num1, float *s_num2){return ms_mag_db<double>(s_num1, s_num2);};



template <class varType>
varType ms_get_max_site(MS_Number<varType> MS_Num, int *site)
{
	return MS_Num.get_max_site(site);
}

double			get_max_site(MS_Number<double> MS_Num,			int *site)	{return ms_get_max_site<double>(MS_Num, site);};
float			get_max_site(MS_Number<float> MS_Num,			int *site)	{return ms_get_max_site<float>(MS_Num, site);};
int				get_max_site(MS_Number<int> MS_Num,				int *site)	{return ms_get_max_site<int>(MS_Num, site);};
short			get_max_site(MS_Number<short> MS_Num,			int *site)	{return ms_get_max_site<short>(MS_Num, site);};
long			get_max_site(MS_Number<long> MS_Num,			int *site)	{return ms_get_max_site<long>(MS_Num, site);};
unsigned int	get_max_site(MS_Number<unsigned int> MS_Num,	int *site)	{return ms_get_max_site<unsigned int>(MS_Num, site);};
unsigned short	get_max_site(MS_Number<unsigned short> MS_Num,	int *site)	{return ms_get_max_site<unsigned short>(MS_Num, site);};
unsigned long	get_max_site(MS_Number<unsigned long> MS_Num,	int *site)	{return ms_get_max_site<unsigned long>(MS_Num, site);};
bool			get_max_site(MS_Number<bool> MS_Num,			int *site)	{return ms_get_max_site<bool>(MS_Num, site);};

template <class varType>
varType ms_get_min_site(MS_Number<varType> MS_Num, int *site)
{
	return MS_Num.get_min_site(site);
}

double			get_min_site(MS_Number<double> MS_Num,			int *site)	{return ms_get_min_site<double>(MS_Num, site);};
float			get_min_site(MS_Number<float> MS_Num,			int *site)	{return ms_get_min_site<float>(MS_Num, site);};
int				get_min_site(MS_Number<int> MS_Num,				int *site)	{return ms_get_min_site<int>(MS_Num, site);};
short			get_min_site(MS_Number<short> MS_Num,			int *site)	{return ms_get_min_site<short>(MS_Num, site);};
long			get_min_site(MS_Number<long> MS_Num,			int *site)	{return ms_get_min_site<long>(MS_Num, site);};
unsigned int	get_min_site(MS_Number<unsigned int> MS_Num,	int *site)	{return ms_get_min_site<unsigned int>(MS_Num, site);};
unsigned short	get_min_site(MS_Number<unsigned short> MS_Num,	int *site)	{return ms_get_min_site<unsigned short>(MS_Num, site);};
unsigned long	get_min_site(MS_Number<unsigned long> MS_Num,	int *site)	{return ms_get_min_site<unsigned long>(MS_Num, site);};
bool			get_min_site(MS_Number<bool> MS_Num,			int *site)	{return ms_get_min_site<bool>(MS_Num, site);};

template <class varType>
MS_Number<varType> ms_clip_max(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	MS_Number<varType>	ret		= MS_Num1;

	return ret.clip_max(MS_Num2);
}

MS_Number<double>			clip_max(MS_Number<double> MS_Num1,			MS_Number<double> MS_Num2)			{return ms_clip_max<double>(MS_Num1, MS_Num2);};
MS_Number<float>			clip_max(MS_Number<float> MS_Num1,			MS_Number<float> MS_Num2)			{return ms_clip_max<float>(MS_Num1, MS_Num2);};
MS_Number<int>				clip_max(MS_Number<int> MS_Num1,			MS_Number<int> MS_Num2)				{return ms_clip_max<int>(MS_Num1, MS_Num2);};
MS_Number<short>			clip_max(MS_Number<short> MS_Num1,			MS_Number<short> MS_Num2)			{return ms_clip_max<short>(MS_Num1, MS_Num2);};
MS_Number<long>				clip_max(MS_Number<long> MS_Num1,			MS_Number<long> MS_Num2)			{return ms_clip_max<long>(MS_Num1, MS_Num2);};
MS_Number<unsigned int>		clip_max(MS_Number<unsigned int> MS_Num1,	MS_Number<unsigned int> MS_Num2)	{return ms_clip_max<unsigned int>(MS_Num1, MS_Num2);};
MS_Number<unsigned short>	clip_max(MS_Number<unsigned short> MS_Num1,	MS_Number<unsigned short> MS_Num2)	{return ms_clip_max<unsigned short>(MS_Num1, MS_Num2);};
MS_Number<unsigned long>	clip_max(MS_Number<unsigned long> MS_Num1,	MS_Number<unsigned long> MS_Num2)	{return ms_clip_max<unsigned long>(MS_Num1, MS_Num2);};

template <class varType>
MS_Number<varType> ms_clip_min(MS_Number<varType> MS_Num1, MS_Number<varType> MS_Num2)
{
	MS_Number<varType>	ret		= MS_Num1;

	return ret.clip_min(MS_Num2);
}

MS_Number<double>			clip_min(MS_Number<double> MS_Num1,			MS_Number<double> MS_Num2)			{return ms_clip_min<double>(MS_Num1, MS_Num2);};
MS_Number<float>			clip_min(MS_Number<float> MS_Num1,			MS_Number<float> MS_Num2)			{return ms_clip_min<float>(MS_Num1, MS_Num2);};
MS_Number<int>				clip_min(MS_Number<int> MS_Num1,			MS_Number<int> MS_Num2)				{return ms_clip_min<int>(MS_Num1, MS_Num2);};
MS_Number<short>			clip_min(MS_Number<short> MS_Num1,			MS_Number<short> MS_Num2)			{return ms_clip_min<short>(MS_Num1, MS_Num2);};
MS_Number<long>				clip_min(MS_Number<long> MS_Num1,			MS_Number<long> MS_Num2)			{return ms_clip_min<long>(MS_Num1, MS_Num2);};
MS_Number<unsigned int>		clip_min(MS_Number<unsigned int> MS_Num1,	MS_Number<unsigned int> MS_Num2)	{return ms_clip_min<unsigned int>(MS_Num1, MS_Num2);};
MS_Number<unsigned short>	clip_min(MS_Number<unsigned short> MS_Num1,	MS_Number<unsigned short> MS_Num2)	{return ms_clip_min<unsigned short>(MS_Num1, MS_Num2);};
MS_Number<unsigned long>	clip_min(MS_Number<unsigned long> MS_Num1,	MS_Number<unsigned long> MS_Num2)	{return ms_clip_min<unsigned long>(MS_Num1, MS_Num2);};

template <class varType>
MS_Number<bool> ms_is_between(MS_Number<varType> MS_Num, MS_Number<varType> MS_NumMin, MS_Number<varType> MS_NumMax, bool include_lims)	
{
	return MS_Num.is_between(MS_NumMin, MS_NumMax, include_lims);
}

MS_Number<bool>				is_between(MS_Number<double> MS_Num,			MS_Number<double> MS_NumMin,			MS_Number<double> MS_NumMax,			bool include_lims)	{return ms_is_between<double>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<float> MS_Num,				MS_Number<float> MS_NumMin,				MS_Number<float> MS_NumMax,				bool include_lims)	{return ms_is_between<float>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<int> MS_Num,				MS_Number<int> MS_NumMin,				MS_Number<int> MS_NumMax,				bool include_lims)	{return ms_is_between<int>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<short> MS_Num,				MS_Number<short> MS_NumMin,				MS_Number<short> MS_NumMax,				bool include_lims)	{return ms_is_between<short>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<long> MS_Num,				MS_Number<long> MS_NumMin,				MS_Number<long> MS_NumMax,				bool include_lims)	{return ms_is_between<long>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned int> MS_Num,		MS_Number<unsigned int> MS_NumMin,		MS_Number<unsigned int> MS_NumMax,		bool include_lims)	{return ms_is_between<unsigned int>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned short> MS_Num,	MS_Number<unsigned short> MS_NumMin,	MS_Number<unsigned short> MS_NumMax,	bool include_lims)	{return ms_is_between<unsigned short>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned long> MS_Num,		MS_Number<unsigned long> MS_NumMin,		MS_Number<unsigned long> MS_NumMax,		bool include_lims)	{return ms_is_between<unsigned long>(MS_Num, MS_NumMin, MS_NumMax, include_lims);};

template <class varType>
MS_Number<bool> ms_is_between(MS_Number<varType> MS_Num, varType NumMin, varType NumMax, bool include_lims)	
{
	return MS_Num.is_between(NumMin, NumMax, include_lims);
}

MS_Number<bool>				is_between(MS_Number<double> MS_Num,			double NumMin,			double NumMax,			bool include_lims)	{return ms_is_between<double>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<float> MS_Num,				float NumMin,			float NumMax,			bool include_lims)	{return ms_is_between<float>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<int> MS_Num,				int NumMin,				int NumMax,				bool include_lims)	{return ms_is_between<int>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<short> MS_Num,				short NumMin,			short NumMax,			bool include_lims)	{return ms_is_between<short>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<long> MS_Num,				long NumMin,			long NumMax,			bool include_lims)	{return ms_is_between<long>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned int> MS_Num,		unsigned int NumMin,	unsigned int NumMax,	bool include_lims)	{return ms_is_between<unsigned int>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned short> MS_Num,	unsigned short NumMin,	unsigned short NumMax,	bool include_lims)	{return ms_is_between<unsigned short>(MS_Num, NumMin, NumMax, include_lims);};
MS_Number<bool>				is_between(MS_Number<unsigned long> MS_Num,		unsigned long NumMin,	unsigned long NumMax,	bool include_lims)	{return ms_is_between<unsigned long>(MS_Num, NumMin, NumMax, include_lims);};

MS_Status::MS_Status()
{
	
	int site=0;

	ms_ext_data	= false;
	ms_value	= new BOOL[CSC_LAST_SITE];

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=store_active_site[site];
}

MS_Status::~MS_Status()
{
	if(!ms_ext_data)
		delete ms_value;
}

MS_Status::MS_Status(MS_Status& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];

	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<int>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<short>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<long>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<unsigned int>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<unsigned short>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<unsigned long>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(MS_Number<bool>& MS_Num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)MS_Num.get_value(site);
}

MS_Status::MS_Status(int *s_num)
{
	ms_ext_data	= true;
	ms_value	= s_num;
}

MS_Status::MS_Status(int num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(short num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(long num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(unsigned int num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(unsigned short num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(unsigned long num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

MS_Status::MS_Status(bool num)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	
	ms_ext_data=false;
	ms_value=new BOOL[last_site];
	
	for (site=0; site < last_site; site++)
		ms_value[site]=(BOOL)(num);
}

BOOL MS_Status::get_value(int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

void MS_Status::set_value(int site, BOOL num)
{
	if(site<CSC_LAST_SITE)
		ms_value[site]=(BOOL)num;
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}
}

void MS_Status::init(void)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=TRUE;
}

void MS_Status::reset(void)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=store_active_site[site];
}

void MS_Status::copy_to(MS_Number<int>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<short>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<long>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<unsigned int>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<unsigned short>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<unsigned long>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? 1.0 : 0.0));
}

void MS_Status::copy_to(MS_Number<bool>& MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		MS_Num.set_value(site,(ms_value[site]==TRUE ? true : false));
}

void MS_Status::copy_to(double *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1.0 : 0.0);
}

void MS_Status::copy_to(float *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? float(1.0) : float(0.0));
}

void MS_Status::copy_to(int *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(short *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(long *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(unsigned int *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(unsigned short *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(unsigned long *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? 1 : 0);
}

void MS_Status::copy_to(bool *s_num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		s_num[site]=(ms_value[site]==TRUE ? true : false);
}

BOOL & MS_Status::operator[](int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

BOOL & MS_Status::operator()(int site)
{
	if(site<CSC_LAST_SITE)
		return ms_value[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_value[0];	
	}
}

MS_Status MS_Status::operator= (const MS_Status& MS_Num)
{
	int site=0;
	if(this==&MS_Num)
		return *this;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=(BOOL)MS_Num.ms_value[site];
	
	return *this;
}

MS_Status MS_Status::operator+ (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]||(BOOL)MS_Num.get_value(site))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}

MS_Status MS_Status::operator- (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]&&(!(BOOL)(MS_Num.get_value(site))))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}

MS_Status MS_Status::operator+= (MS_Status MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=ms_value[site]||(BOOL)(MS_Num.get_value(site));
	
	return *this;
}

MS_Status MS_Status::operator-= (MS_Status MS_Num)
{
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		ms_value[site]=ms_value[site]&&(!(BOOL)(MS_Num.get_value(site)));
	
	return *this;
}


MS_Status MS_Status::operator== (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]==(BOOL)MS_Num.get_value(site))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}

MS_Status MS_Status::operator!= (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]!=(BOOL)MS_Num.get_value(site))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}

MS_Status MS_Status::operator!()
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
		ret.set_value(site,!(BOOL)(ms_value[site]));

	return ret;
}

MS_Status MS_Status::operator&& (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]&&(BOOL)(MS_Num.get_value(site)))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}

MS_Status MS_Status::operator|| (MS_Status MS_Num)
{
	int site=0;
	MS_Status ret;

	for (site=0; site < CSC_LAST_SITE; site++)
	{
		if(ms_value[site]||(BOOL)(MS_Num.get_value(site)))
			ret.set_value(site,TRUE);
		else
			ret.set_value(site,FALSE);
	}
	return ret;
}


MS_Status	Active_Site(active_site);



template <class arrType>
MS_Array<arrType>::MS_Array()
{
	

	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=0;
	ms_array=NULL;

}

template <class arrType>
MS_Array<arrType>::MS_Array(int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	

	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]=0;
	}
}

template <class arrType>
MS_Array<arrType>::~MS_Array()
{
	int site=0;
	int	sample=0;

	
	
	if((!ms_ext_data)&&(ms_array!=NULL))	
	{
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		if(ms_array!=NULL)
			delete[] ms_array;
	}

}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Array<double>& MS_Ary)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data	= false;
		
	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;
	ms_ary_size	= MS_Ary.get_size();

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Ary.get_value(site,sample);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Array<float>& MS_Ary)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data	= false;
		
	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;
	ms_ary_size	= MS_Ary.get_size();

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Ary.get_value(site,sample);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Array<int>& MS_Ary)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data	= false;
	
	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;
	ms_ary_size	= MS_Ary.get_size();

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Ary.get_value(site,sample);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<double>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<float>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<int>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<short>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<long>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<unsigned int>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<unsigned short>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<unsigned long>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(MS_Number<bool>& MS_Num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MS_Num.get_value(site);
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(double * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(float * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(int * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(short * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;	
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	ms_array=new arrType* [last_site];
	for (site=0; site < last_site; site++)
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(long * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;	
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	ms_array=new arrType* [last_site];
	for (site=0; site < last_site; site++)
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(unsigned int * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(unsigned short * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(unsigned long * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(bool * s_num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)s_num[site];
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(double num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(float num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(int num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(short num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	ms_array=new arrType* [last_site];
	for (site=0; site < last_site; site++)
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}template <class arrType>
MS_Array<arrType>::MS_Array(long num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	ms_array=new arrType* [last_site];
	for (site=0; site < last_site; site++)
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}


template <class arrType>
MS_Array<arrType>::MS_Array(unsigned int num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(unsigned short num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(unsigned long num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
MS_Array<arrType>::MS_Array(bool num, int size)
{
	int site=0;
	int	last_site	= (CSC_LAST_SITE > 0 ? CSC_LAST_SITE : CSC_MAX_SITES);		
	int	sample=0;

	
	
	ms_ext_data=false;

	if(typeid(arrType)==typeid(double))				ms_id=MS_DOUBLE;
	else if(typeid(arrType)==typeid(float))			ms_id=MS_FLOAT;
	else if(typeid(arrType)==typeid(int))			ms_id=MS_INT;
	else if(typeid(arrType)==typeid(short))			ms_id=MS_SHORT;		
	else if(typeid(arrType)==typeid(long))			ms_id=MS_LONG;		
	else if(typeid(arrType)==typeid(unsigned int))	ms_id=MS_SUINT;
	else if(typeid(arrType)==typeid(unsigned short))ms_id=MS_SUSHORT;
	else if(typeid(arrType)==typeid(unsigned long))	ms_id=MS_SULONG;
	else if(typeid(arrType)==typeid(bool))			ms_id=MS_BOOL;

	ms_ary_size=size;

	
	
	ms_array=new arrType* [last_site];			
	for (site=0; site < last_site; site++)		
	{
		ms_array[site]=new arrType[ms_ary_size];
		if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}
}

template <class arrType>
arrType MS_Array<arrType>::get_value(int site, int sample)
{
	if((site<CSC_LAST_SITE)&&(sample<ms_ary_size))
		return ms_array[site][sample];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i or array size %i", site, CSC_LAST_SITE-1, ms_ary_size);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_array[0][0];	
	}
}

template <class arrType>
void MS_Array<arrType>::set_value(int site, int sample, arrType num)
{
	if((site<CSC_LAST_SITE)&&(sample<ms_ary_size))
		ms_array[site][sample]=arrType(num);
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i or array size %i", site, CSC_LAST_SITE-1, ms_ary_size);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}
}


template <class arrType>
MS_Number<arrType> MS_Array<arrType>::get_value(int sample)
{
	MS_Number<arrType>	ret_Ms_Num;
	int site=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		if((site<CSC_LAST_SITE)&&(sample<ms_ary_size))
			ret_Ms_Num[site]=ms_array[site][sample];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds array size %i", CSC_LAST_SITE-1, ms_ary_size);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}
	return ret_Ms_Num;
}

template <class arrType>
void MS_Array<arrType>::set_value(int sample, MS_Number<arrType> MS_Num)
{
	int site=0;

	if((site<CSC_LAST_SITE)&&(sample<ms_ary_size))
		ms_array[site][sample]=MS_Num[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds array size %i", CSC_LAST_SITE-1, ms_ary_size);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}
}


template <class arrType>
MsNumIdType MS_Array<arrType>::get_type(void)
{
	return ms_id;
}

template <class arrType>
int MS_Array<arrType>::get_size(void)
{
	return ms_ary_size;
}


template <class arrType>
void MS_Array<arrType>::init(void)
{
	
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]=0;
}

template <class arrType>
void MS_Array<arrType>::init(int size)
{
	

	int site=0;
	int sample=0;

	
	if((!ms_ext_data)&&(ms_array!=NULL)&&(size!=ms_ary_size))	
	{
		ms_ary_size=size;

		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		for (site=0; site < CSC_LAST_SITE; site++)
		{
			ms_array[site]=new arrType[ms_ary_size];
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=0;
		}
	}
}


template <class arrType>
MS_Array<arrType> MS_Array<arrType>::Abs(int Start, int Stop)		
{
	
	
	
	int site=0;
	int	sample=0;

	MS_Array<arrType>	ret_ary(ms_ary_size);

	if((ms_id!=MS_FLOAT)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "Abs applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
	{
		if(Start==-1)	Start=0;
		if(Stop==-1)	Stop=ms_ary_size-1;

		if(Stop<(Start+1))
			MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		else
		{
			for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
				for (sample=0; sample <= ms_ary_size; sample++)
					if((sample>=Start)&&(sample<=Stop))
						ret_ary[site][sample]=(ms_array[site][sample]<0 ? -ms_array[site][sample] : ms_array[site][sample]);
					else
						ret_ary[site][sample]=ms_array[site][sample];
		}
	}
	return ret_ary;
}

template <class arrType>

MS_Number<arrType> MS_Array<arrType>::Mean(int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_ave=0;

	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			
			for (sample=Start; sample <= Stop; sample++)
				
				ret_ave[site]+=(double)ms_array[site][sample];
	}



	ret_ave/=(Stop-Start+1);	
	return (MS_Number<arrType>)ret_ave;
}

template <class arrType>

MS_Number<arrType> MS_Array<arrType>::Rms(int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_rms=0;

	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			
			for (sample=Start; sample <= Stop; sample++)
				ret_rms[site]+=pow((double)ms_array[site][sample],2.0);

	
		ret_rms/=(Stop-Start+1);	
		ret_rms=ret_rms.math_func2(pow,0.5);
	}
	return (MS_Number<arrType>)ret_rms;	
}

template <class arrType>
MS_Number<arrType> MS_Array<arrType>::Stdev(int Start, int Stop)	
{

	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_stdev=0;
	MS_Number<double>	mean_temp=0;

	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			for (sample=Start; sample <= Stop; sample++)
				mean_temp[site]+=(double)ms_array[site][sample];

			mean_temp[site]/=(Stop-Start+1);

			for (sample=Start; sample <= Stop; sample++)
				ret_stdev[site]+=pow((double)(ms_array[site][sample]-mean_temp[site]),2.0);

			ret_stdev[site]=pow((double)(ret_stdev[site]/(Stop-Start+1)),0.5);
		}
	}
	
	return (MS_Number<arrType>)ret_stdev;
}

template <class arrType>

MS_Number<arrType> MS_Array<arrType>::Min(int Start, int Stop)	
{

	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_min;

	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			ret_min[site]=ms_array[site][Start];		

			
			for (sample=Start+1; sample <= Stop; sample++)	
				if((double)ms_array[site][sample]<ret_min[site])
					ret_min[site]=(double)ms_array[site][sample];
		}
	}

	return (MS_Number<arrType>)ret_min;	
}

template <class arrType>

MS_Number<arrType> MS_Array<arrType>::Max(int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_max;

	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			ret_max[site]=ms_array[site][Start];		

			
			for (sample=Start+1; sample <= Stop; sample++)	
				if((double)ms_array[site][sample]>ret_max[site])
					ret_max[site]=(double)ms_array[site][sample];
		}
	}
	
	return (MS_Number<arrType>)ret_max;	
}

template <class arrType>
MS_Number<arrType> MS_Array<arrType>:: Least(int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;

	MS_Number<double>	ret_least;

	if((ms_id!=MS_FLOAT)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "Least applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
	{
		if(Start==-1)	Start=0;
		if(Stop==-1)	Stop=ms_ary_size-1;

		if(Stop<(Start+1))
			MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		else
		{
			for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			{
				ret_least[site]=(double)ms_array[site][Start];

				for (sample=Start+1; sample <= Stop; sample++)
					if(fabs((double)ms_array[site][sample])<fabs(ret_least[site]))
						ret_least[site]=(double)ms_array[site][sample];
			}
		}
	}
	return (MS_Number<arrType>)ret_least;
}


template <class arrType>

void MS_Array<arrType>::mean_stdev_rms(MS_Number<arrType> &Mean, MS_Number<arrType> &Stdev, MS_Number<arrType> &Rms, int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;

	
	MS_Number<double>	mean_temp=0;
	MS_Number<double>	stdev_temp=0;
	MS_Number<double>	rms_temp=0;





	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			for (sample=Start; sample <= Stop; sample++)
			{
				mean_temp[site]+=(double)ms_array[site][sample];
				rms_temp[site]+=pow((double)ms_array[site][sample],2.0);
			}


			mean_temp[site]/=(Stop-Start+1);	
			rms_temp[site]=pow((double)(rms_temp[site]/(Stop-Start+1)),0.5);
		}

		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			for (sample=Start; sample <= Stop; sample++)
				stdev_temp[site]+=pow((double)(ms_array[site][sample]-mean_temp[site]),2.0);

			stdev_temp[site]=pow((double)(stdev_temp[site]/(Stop-Start+1)),0.5);
		}
	}

	Mean	= (MS_Number<arrType>)mean_temp;
	Stdev	= (MS_Number<arrType>)stdev_temp;
	Rms		= (MS_Number<arrType>)rms_temp;
}

template <class arrType>

void MS_Array<arrType>::min_max_idx(MS_Number<arrType> &Min, MS_Number<arrType> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx, int Start, int Stop)	
{

	
	int site=0;
	int sample=0;

	Min=0;
	Max=0;

	
	if(Start==-1)	Start=0;
	if(Stop==-1)	Stop=ms_ary_size-1;

	if(Stop<(Start+1))
		MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
	{





		
		Min[site]=ms_array[site][Start];
		MinIdx[site]=Start;
		Max[site]=ms_array[site][Start];
		MaxIdx[site]=Start;

		for (sample=Start+1; sample <= Stop; sample++)
		{
			if((double)ms_array[site][sample]<Min[site])
			{
				
				Min[site]=ms_array[site][sample];		
				MinIdx[site]=sample;
			}
			if((double)ms_array[site][sample]>Max[site])
			{
				
				Max[site]=ms_array[site][sample];		
				MaxIdx[site]=sample;
			}
		}
	}
}

template <class arrType>
void MS_Array<arrType>::least_idx(MS_Number<arrType> &Least, MS_Number<int> &LeastIdx, int Start, int Stop)	
{
	
	
	int site=0;
	int sample=0;
	arrType temp_in, temp_out;

	if((ms_id!=MS_FLOAT)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "least_idx applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
	{
		Least=0;
		if(Start==-1)	Start=0;
		if(Stop==-1)	Stop=ms_ary_size-1;

		if(Stop<(Start+1))
			MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		else
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			Least[site]=ms_array[site][Start];
			temp_in = temp_out = (Least[site]<0 ? - Least[site] : Least[site]);
			LeastIdx[site]=Start;

			for (sample=Start+1; sample <= Stop; sample++)
			{
				temp_in=(ms_array[site][sample]<0 ? -ms_array[site][sample] : ms_array[site][sample]);
				if(temp_in<temp_out)
				{
					temp_out=temp_in;
					Least[site]=ms_array[site][sample];
					LeastIdx[site]=sample;
				}
			}
		}
	}
}


template <class arrType>
MS_Array<arrType>  MS_Array<arrType>::ClipMin(MS_Number<double> ClipMinVal, MS_Number<int> &Idx, MS_Number<int> Start, MS_Number<int> Stop)
{
	
	
	int site=0;
	int	sample=0;

	
	Idx=-1;

	MS_Array<arrType>	ret_ary(ms_ary_size);

	if((ms_id==MS_BOOL)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "ClipMin applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			if(Start[site]==-1)	Start[site]	= 0;
			if(Stop[site]==-1)	Stop[site]	= ms_ary_size-1;

			if(Stop[site]<(Start[site]+1))
				MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			else
				for (sample=0; sample <= ms_ary_size; sample++)
					if((sample>=Start[site])&&(sample<=Stop[site]))
					{
						if(ms_array[site][sample]<ClipMinVal[site])
						{
							ret_ary[site][sample]=ClipMinVal[site];
							if(Idx[site]<0)
								Idx[site]=sample;
						}
						else
							ret_ary[site][sample]=ms_array[site][sample];
					}
					else
						ret_ary[site][sample]=ms_array[site][sample];
		}
	return ret_ary;
}

template <class arrType>
MS_Array<arrType>  MS_Array<arrType>::ClipMax(MS_Number<double> ClipMaxVal, MS_Number<int> &Idx, MS_Number<int> Start, MS_Number<int> Stop)
{
	
	
	int site=0;
	int	sample=0;

	
	Idx=-1;

	MS_Array<arrType>	ret_ary(ms_ary_size);

	if((ms_id==MS_BOOL)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "ClipMax applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			if(Start[site]==-1)	Start[site]	= 0;
			if(Stop[site]==-1)	Stop[site]	= ms_ary_size-1;

			if(Stop[site]<(Start[site]+1))
				MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			else
				for (sample=0; sample <= ms_ary_size; sample++)
					if((sample>=Start[site])&&(sample<=Stop[site]))
					{
						if(ms_array[site][sample]>ClipMaxVal[site])
						{
							ret_ary[site][sample]=ClipMaxVal[site];
							if(Idx[site]<0)
								Idx[site]=sample;
						}
						else
							ret_ary[site][sample]=ms_array[site][sample];
					}
					else
						ret_ary[site][sample]=ms_array[site][sample];
		}
	return ret_ary;
}

template <class arrType>
MS_Number<int>  MS_Array<arrType>::Trigger(MS_Number<double> TrigThreshold, TriggerType Polarity, MS_Number<int> Start, MS_Number<int> Stop)
{
	
	

	int site=0;
	int	sample=0;

	
	MS_Number<int>		ret_idx(-1);

	if((ms_id==MS_BOOL)&&(ms_id!=MS_DOUBLE)&&(ms_id!=MS_INT))
		{
			char ErrorMessage[100];
			sprintf(ErrorMessage, "Trigger applies to multisite arrays of float, double and int only");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}
	else
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		{
			if(Start[site]==-1)	Start[site]	= 0;
			if(Stop[site]==-1)	Stop[site]	= ms_ary_size-1;

			if(Stop[site]<(Start[site]+1))
				MessageBox(NULL,"Stop must be greater than Start!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			else if(ret_idx[site]<0)
				for (sample=Start[site]+1; sample <= Stop[site]; sample++)
					if	(
						((Polarity==POS)&&(ms_array[site][sample-1]<TrigThreshold[site])&&(ms_array[site][sample]>=TrigThreshold[site]))||
						((Polarity==NEG)&&(ms_array[site][sample-1]>TrigThreshold[site])&&(ms_array[site][sample]<=TrigThreshold[site]))
						)
					{
						ret_idx[site]=sample;
						break;
					}
		}
	return ret_idx;
}


template <class arrType>
arrType* MS_Array<arrType>::operator[](int site)
{
	if(site<CSC_LAST_SITE)
		return ms_array[site];
	else
	{
		char ErrorMessage[100];
		sprintf(ErrorMessage, "Index %i exceeds last site %i", site, CSC_LAST_SITE-1);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return ms_array[0];	
	}
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator= (const MS_Array<arrType>& MS_Ary)
{
	int site=0;
	int sample=0;

	if(this==&MS_Ary)
		return *this;

	ms_ext_data	= false;		
	ms_id		= MS_Ary.ms_id;
	
	
	if((ms_ary_size != MS_Ary.ms_ary_size)&&(ms_array!=NULL))	
	{
		
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		
		for (site=0; site < CSC_LAST_SITE; site++)
		{
			ms_array[site]=new arrType[ms_ary_size];
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=0;
		}
	}

	
	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]=(arrType)MS_Ary.ms_array[site][sample];

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (double num)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (float num)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (int num)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)num;
	}

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MsNum[site];
	}

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MsNum[site];
	}

	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator= (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	if((ms_ary_size != 0)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
			for (sample=0; sample < ms_ary_size; sample++)
				ms_array[site][sample]=(arrType)MsNum[site];
	}

	return *this;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator+ (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+MS_Ary.get_value(site, sample));
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (double num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (float num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (int num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+ (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]+(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator- (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-MS_Ary.get_value(site, sample));
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (double num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (float num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (int num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator- (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]-(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator* (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*MS_Ary.get_value(site, sample));
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (double num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (float num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (int num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator* (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]*(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator/ (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/MS_Ary.get_value(site, sample));
	
	return ret;
}


template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (double num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (float num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (int num)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)num);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)MsNum[site]);
	
	return ret;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/ (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	MS_Array<arrType> ret(ms_ary_size);

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ret.set_value(site,sample, ms_array[site][sample]/(arrType)MsNum[site]);
	
	return ret;
}


template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator+= (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ms_array[site][sample]+=MS_Ary.ms_array[site][sample];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (double num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (float num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (int num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator+= (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]+=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator-= (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ms_array[site][sample]-=MS_Ary.ms_array[site][sample];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (double num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (float num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (int num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator-= (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]-=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator*= (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ms_array[site][sample]*=MS_Ary.ms_array[site][sample];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (double num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (float num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (int num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator*= (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]*=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>
MS_Array<arrType> MS_Array<arrType>::operator/= (MS_Array<arrType> MS_Ary)
{
	int site=0;
	int sample=0;
	int	min_ary_size = ((ms_ary_size < MS_Ary.ms_ary_size ) ? ms_ary_size : MS_Ary.ms_ary_size );

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < min_ary_size; sample++)
			ms_array[site][sample]/=MS_Ary.ms_array[site][sample];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (double num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (float num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (int num)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)num;
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (MS_Number<double> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (MS_Number<float> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)MsNum[site];
	
	return *this;
}

template <class arrType>	
MS_Array<arrType> MS_Array<arrType>::operator/= (MS_Number<int> MsNum)
{
	int site=0;
	int sample=0;

	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < ms_ary_size; sample++)
			ms_array[site][sample]/=(arrType)MsNum[site];
	
	return *this;
}

template class __declspec(dllexport) MS_Array<double>;
template class __declspec(dllexport) MS_Array<float>;
template class __declspec(dllexport) MS_Array<int>;


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);

}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, unsigned short fail_bin, char *notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, unsigned short fail_bin, schar notes)
{
	suint	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, unsigned short fail_bin, schar notes)
{
	sfloat	_test_val;

	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, MS_Number<unsigned short> fail_bin, char *notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	suint	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, MS_Number<unsigned short> fail_bin, schar notes)
{
	sfloat	_test_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, notes);
}



void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, unsigned short fail_bin,MS_Number<unsigned int> min_val,MS_Number<unsigned int> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, unsigned short fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);

}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long> test_val, short power, unsigned short fail_bin,MS_Number<unsigned long> min_val,MS_Number<unsigned long> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin , _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, unsigned short fail_bin,MS_Number<int> min_val,MS_Number<int> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	test_val.copy_to(_test_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, unsigned short fail_bin,MS_Number<float> min_val,MS_Number<float> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, unsigned short fail_bin,MS_Number<double> min_val,MS_Number<double> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, unsigned short fail_bin,MS_Number<bool> min_val,MS_Number<bool> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, unsigned short fail_bin,MS_Number<unsigned int> min_val,MS_Number<unsigned int> max_val, schar notes)
{
	suint	_test_val;
	suint	_min_val;
	suint	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, unsigned short fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	test_val.copy_to(_min_val);
	test_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long> test_val, short power, unsigned short fail_bin,MS_Number<unsigned long> min_val,MS_Number<unsigned long> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, unsigned short fail_bin,MS_Number<int> min_val,MS_Number<int> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, unsigned short fail_bin,MS_Number<float> min_val,MS_Number<float> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, unsigned short fail_bin,MS_Number<double> min_val,MS_Number<double> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, unsigned short fail_bin,MS_Number<bool> min_val,MS_Number<bool> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	
	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	data_log(func, test_no, _test_val, power, fail_bin, _min_val, _max_val, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned int> min_val,MS_Number<unsigned int> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned short> min_val,MS_Number<unsigned short> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned long>	min_val,MS_Number<unsigned long>	max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<int> min_val,MS_Number<int> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<float> min_val,MS_Number<float> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<double> min_val,MS_Number<double> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<bool> min_val,MS_Number<bool> max_val, char *notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}


void  data_log(test_function& func, short test_no, MS_Number<unsigned int> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned int> min_val,MS_Number<unsigned int> max_val, schar notes)
{
	suint	_test_val;
	suint	_min_val;
	suint	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned short>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned short>	min_val,MS_Number<unsigned short>	max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<unsigned long>	test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<unsigned long>	min_val,MS_Number<unsigned long>	max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<int> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<int> min_val,MS_Number<int> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<float> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<float> min_val,MS_Number<float> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<double> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<double> min_val,MS_Number<double> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}

void  data_log(test_function& func, short test_no, MS_Number<bool> test_val, short power, MS_Number<unsigned short> fail_bin,MS_Number<bool> min_val,MS_Number<bool> max_val, schar notes)
{
	sfloat	_test_val;
	sfloat	_min_val;
	sfloat	_max_val;
	sushort _fail_bin;

	test_val.copy_to(_test_val);
	min_val.copy_to(_min_val);
	max_val.copy_to(_max_val);
	fail_bin.copy_to(_fail_bin);
	data_log(func, test_no, _test_val, power, _fail_bin, _min_val, _max_val, notes);
}


void dc_force(short pin, float current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	voltage.copy_to(_voltage);
	dc_force(pin, current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, double current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	voltage.copy_to(_voltage);
	dc_force(pin, (float)current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, MS_Number<float> current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	current.copy_to(_current);
	dc_force(pin, _current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, MS_Number<float> current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	current.copy_to(_current);
	dc_force(pin, _current, (float)voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, MS_Number<float> current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;
	sfloat _voltage;

	current.copy_to(_current);
	voltage.copy_to(_voltage);
	dc_force(pin, _current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin_list, float current, MS_Number<float> *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		voltage[list_depth-1-n].copy_to(_voltage);
		dc_force(pin, current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, double current, MS_Number<float> *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		voltage[list_depth-1-n].copy_to(_voltage);
		dc_force(pin, (float)current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, MS_Number<float> *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		dc_force(pin, _current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, MS_Number<float> *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		dc_force(pin, _current, (float)voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, MS_Number<float> *current, MS_Number<float> *voltage,	short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		voltage[list_depth-1-n].copy_to(_voltage);
		dc_force(pin, _current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}


void  cap_force(short pin, short force_mode, float transition_time, float current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	voltage.copy_to(_voltage);
	cap_force(pin, force_mode, transition_time, current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin, short force_mode, float transition_time, double current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	voltage.copy_to(_voltage);
	cap_force(pin, force_mode, transition_time, (float)current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin, short force_mode, float transition_time, MS_Number<float> current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	current.copy_to(_current);
	cap_force(pin, force_mode, transition_time, _current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin, short force_mode, float transition_time, MS_Number<float> current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	current.copy_to(_current);
	cap_force(pin, force_mode, transition_time, _current, (float)voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin, short force_mode, float transition_time, MS_Number<float> current, MS_Number<float> voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;
	sfloat _voltage;

	current.copy_to(_current);
	voltage.copy_to(_voltage);
	cap_force(pin, force_mode, transition_time, _current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin_list, short force_mode, float transition_time, float current, MS_Number<float> *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		voltage[list_depth-1-n].copy_to(_voltage);
		cap_force(pin, force_mode, transition_time, current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list, short force_mode, float transition_time, double current, MS_Number<float> *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		voltage[list_depth-1-n].copy_to(_voltage);
		cap_force(pin, force_mode, transition_time, (float)current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list, short force_mode, float transition_time, MS_Number<float> *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		cap_force(pin, force_mode, transition_time, _current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list, short force_mode, float transition_time, MS_Number<float> *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		cap_force(pin, force_mode, transition_time, _current, (float)voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list, short force_mode, float transition_time, MS_Number<float> *current, MS_Number<float> *voltage,	short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	sfloat _current;
	sfloat _voltage;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		current[list_depth-1-n].copy_to(_current);
		voltage[list_depth-1-n].copy_to(_voltage);
		cap_force(pin, force_mode, transition_time, _current, _voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}


void dc_measure(short pin,short mode, MS_Number<double> &result ,short ave_num, short d_range, short wait_us)
{
	
	sfloat _result;

	dc_measure(pin, mode, _result, ave_num, d_range, wait_us);
	result=_result;
}

void dc_measure(short pin,short mode, MS_Number<float> &result ,short ave_num, short d_range, short wait_us)
{
	
	sfloat _result;

	dc_measure(pin, mode, _result, ave_num, d_range, wait_us);
	result=_result;
}

void dc_measure(short pin_list, short mode, MS_Number<double> *result_list, short ave_num, short d_range, short wait_us)
{
	
	

	sfloat _result;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_measure(pin, mode, _result, ave_num, d_range, wait_us);
		
		result_list[list_depth-1-n]=_result;

		pin_ptr = pin_ptr->nextptr;
	}	
}

void dc_measure(short pin_list, short mode, MS_Number<float> *result_list, short ave_num, short d_range, short wait_us)
{



	sfloat _result;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_measure(pin, mode, _result, ave_num, d_range, wait_us);
		
		result_list[list_depth-1-n]=_result;

		pin_ptr = pin_ptr->nextptr;
	}	
}



void tmu_read(short pin, MS_Number<double> &result, double timeout)	
{
	sfloat _result;

	tmu_read(pin, _result, timeout);
	result=_result;
}


void tmu_read(short pin, MS_Number<float> &result, double timeout)	
{
	sfloat _result;

	tmu_read(pin, _result, timeout);
	result=_result;
}

void tmu_get_bit(short pin, MS_Number<bool> &result)
{
	sbool _result;

	tmu_get_bit(pin, _result);
	result=_result;
}


void oal_set_compensation(short pin, MS_Number<int> PoleStab, MS_Number<int> ZeroStab)
{
	sint _PoleStab;
	sint _ZeroStab;

	PoleStab.copy_to(_PoleStab);
	ZeroStab.copy_to(_ZeroStab);

	oal_set_compensation(pin, _PoleStab, _ZeroStab);
}

void oal_set_compensation(short pin_list, MS_Number<int> *PoleStab_list, MS_Number<int> *ZeroStab_list)
{
	sint _PoleStab;
	sint _ZeroStab;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}
	
	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		PoleStab_list[list_depth-1-n].copy_to(_PoleStab);
		ZeroStab_list[list_depth-1-n].copy_to(_ZeroStab);
		
		oal_set_compensation(pin, _PoleStab, _ZeroStab);

		pin_ptr = pin_ptr->nextptr;
	}	
}

void oal_get_compensation(short pin, MS_Number<int> &PoleStab, MS_Number<int> &ZeroStab)
{
	sint _PoleStab;
	sint _ZeroStab;

	oal_get_compensation(pin, _PoleStab, _ZeroStab);

	PoleStab=_PoleStab;
	ZeroStab=_ZeroStab;
}

void oal_get_compensation(short pin_list, MS_Number<int> *PoleStab_list, MS_Number<int> *ZeroStab_list)
{
	sint _PoleStab;
	sint _ZeroStab;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}
	
	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		oal_get_compensation(pin, _PoleStab, _ZeroStab);

		PoleStab_list[list_depth-1-n]=_PoleStab;
		ZeroStab_list[list_depth-1-n]=_ZeroStab;
		
		pin_ptr = pin_ptr->nextptr;
	}	
}

void oal_read_ia_offset(short pin, unsigned short ia_range, MS_Number<float> &zero_null, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{
	sfloat _zero_null;

	oal_read_ia_offset(pin, ia_range, _zero_null, nsamples, reject_50Hz, use_internal_short_rly);

	zero_null=_zero_null;
}

void oal_read_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *zero_null_list, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{



	sfloat *_zero_null_ptr;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	_zero_null_ptr=new sfloat [list_depth];

	oal_read_ia_offset(pin_list, ia_range, _zero_null_ptr, nsamples, reject_50Hz, use_internal_short_rly);


	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		zero_null_list[n]=_zero_null_ptr[n];

		pin_ptr = pin_ptr->nextptr;
	}	
	
	delete[] _zero_null_ptr;
}

int oal_cal_ia_offset(short pin, unsigned short ia_range, MS_Number<float> &zero_null, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{
	int ret;
	sfloat _zero_null;

	ret=oal_cal_ia_offset(pin, ia_range, _zero_null, recalibrate, nsamples, reject_50Hz, use_internal_short_rly, start_from_existing_cal);

	zero_null=_zero_null;

	return ret;
}

int oal_cal_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *zero_null_list, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{



	int ret;
	sfloat *_zero_null_ptr;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	_zero_null_ptr=new sfloat [list_depth];

	ret=oal_cal_ia_offset(pin_list, ia_range, _zero_null_ptr, recalibrate, nsamples, reject_50Hz, use_internal_short_rly, start_from_existing_cal);


	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		zero_null_list[n]=_zero_null_ptr[n];

		pin_ptr = pin_ptr->nextptr;
	}	
	
	delete[] _zero_null_ptr;
	return ret;
}

void oal_set_ia_offset(short pin, unsigned short ia_range, MS_Number<float> ia_offset)
{
	sfloat _ia_offset;

	ia_offset.copy_to(_ia_offset);
	oal_set_ia_offset(pin, ia_range, _ia_offset);
}

void oal_set_ia_offset(short pin_list, unsigned short ia_range, MS_Number<float> *ia_offset)
{
	sfloat _ia_offset;

	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ia_offset[list_depth-1-n].copy_to(_ia_offset);
		oal_set_ia_offset(pin, ia_range, _ia_offset);

		pin_ptr = pin_ptr->nextptr;
	}
}


extern void ac_measure(short pin, MS_Number<float> &result ,short ave_num, short rms_range, short coupling, short wait_us)
{
	sfloat _result;

	ac_measure(pin, _result, ave_num, rms_range, coupling, wait_us);

	result=_result;
}

void ddd_get_vih(short pin_list, MS_Number<float> *vih_list)
{
	short			pin;
	int				list_depth=0;
	int				n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;

	sfloat			_single_pin_vih;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vih(pin, _single_pin_vih);

		
		vih_list[list_depth-1-n]=_single_pin_vih;

		pin_ptr = pin_ptr->nextptr;
	}
}

void ddd_get_vih(short pin, MS_Number<float> &vih)
{
	sfloat _vih;

	ddd_get_vih(pin, _vih);

	vih=_vih;
}

void ddd_get_vil(short pin_list, MS_Number<float> *vil_list)
{
	short			pin;
	int				list_depth=0;
	int				n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;

	sfloat			_single_pin_vil;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vih(pin, _single_pin_vil);

		
		vil_list[list_depth-1-n]=_single_pin_vil;

		pin_ptr = pin_ptr->nextptr;
	}
}

void ddd_get_vil(short pin, MS_Number<float> &vil)
{
	sfloat _vil;

	ddd_get_vih(pin, _vil);

	vil=_vil;
}

void ddd_get_vref(short pin_list, MS_Number<float> *vref_list)
{
	short			pin;
	int				list_depth=0;
	int				n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;

	sfloat			_single_pin_vref;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vih(pin, _single_pin_vref);

		
		vref_list[list_depth-1-n]=_single_pin_vref;

		pin_ptr = pin_ptr->nextptr;
	}
}

void ddd_get_vref(short pin, MS_Number<float> &vref)
{
	sfloat _vref;

	ddd_get_vih(pin, _vref);

	vref=_vref;
}

void ddd_get_timings(short pin, MS_Number<float> &tg1, MS_Number<float> &tg2)
{
	sfloat _tg1, _tg2;

	ddd_get_timings(pin, _tg1, _tg2);

	tg1=_tg1;
	tg2=_tg2;
}

void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail)
{
	sint _pass_fail;
	
	ddd_read_pattern_result(pattern_name, _pass_fail);

	pass_fail			= _pass_fail;
}

void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail)
{
	sint _pass_fail;
	
	ddd_read_pattern_result(pattern_name, _pass_fail);

	pass_fail			= _pass_fail;
}

void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail, MS_Number<int> &first_fail_address)
{
	sint _pass_fail;
	sint _first_fail_address;
	
	ddd_read_pattern_result(pattern_name, _pass_fail, _first_fail_address);

	pass_fail			= _pass_fail;
	first_fail_address	= _first_fail_address;
}

void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail, MS_Number<int> &first_fail_address)
{
	sint _pass_fail;
	sint _first_fail_address;
	
	ddd_read_pattern_result(pattern_name, _pass_fail, _first_fail_address);

	pass_fail			= _pass_fail;
	first_fail_address	= _first_fail_address;
}


void ddd_read_pattern_result(char *pattern_name, MS_Number<bool> &pass_fail, MS_Number<int> &first_fail_address, MS_Number<int> &first_fail_pin, char *entry_label, char *exit_label, int *fail_count, short pin_name)	
{
	sint _pass_fail;
	sint _first_fail_address;
	sint _first_fail_pin;

	
	ddd_read_pattern_result(pattern_name, _pass_fail, _first_fail_address, _first_fail_pin, entry_label, exit_label, fail_count, pin_name);	

	pass_fail			= _pass_fail;
	first_fail_address	= _first_fail_address;
	first_fail_pin		= _first_fail_pin;
}


void ddd_read_pattern_result(char *pattern_name, MS_Number<int> &pass_fail, MS_Number<int> &first_fail_address, MS_Number<int> &first_fail_pin, char *entry_label, char *exit_label, int *fail_count, short pin_name)	
{
	sint _pass_fail;
	sint _first_fail_address;
	sint _first_fail_pin;

	
	ddd_read_pattern_result(pattern_name, _pass_fail, _first_fail_address, _first_fail_pin, entry_label, exit_label, fail_count, pin_name);	

	pass_fail			= _pass_fail;
	first_fail_address	= _first_fail_address;
	first_fail_pin		= _first_fail_pin;
}

void ddd_dig_src(short pin_list, char *pattern_name, MS_Number<unsigned long> src_data, char *entry_label, int displacement)
{
	sulong _src_data;
	src_data.copy_to(_src_data);
	ddd_dig_src(pin_list, pattern_name, _src_data, entry_label, displacement);
}

void ddd_dig_cap(short pin_list, char *pattern_name, MS_Number<unsigned long> &cap_data, char *entry_label, int displacement)
{
	sulong _cap_data;
	ddd_dig_cap(pin_list, pattern_name, _cap_data, entry_label, displacement);
	cap_data=_cap_data;
}



#ifndef	LegacyXerxes


void xvi_read_average(short pin, MS_Number<double> &result)	
{
	sdouble _result;

	xvi_read_average(pin, _result);	
	result=_result;
}


void xvi_read_average(short pin_list, MS_Number<double> *result_list)	
{
	short			pin;
	int				list_depth=0;
	int				n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;

	sdouble			_single_pin_result;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		
		xvi_read_average(pin, _single_pin_result);	

		
		result_list[list_depth-1-n]=_single_pin_result;

		pin_ptr = pin_ptr->nextptr;
	}
}


void xvi_read_capture(short pin, MSDOUBLE_WF &xvi_capture)	
{
	
	
	
	int			num_samples;
	sdouble_wf	sCaptureWave;
	CSC_STATUS	ret_status;

	
	num_samples=xvi_read_capture(pin, sCaptureWave);	
	xvi_capture.init(sCaptureWave,num_samples);
	return;
}

void xvi_read_capture(short pin, MSFLOAT_WF &xvi_capture)	
{
	
	
	
	int			num_samples;
	sdouble_wf	sCaptureWave;
	MSDOUBLE_WF xvi_capture_;
	CSC_STATUS	ret_status;

	num_samples=xvi_read_capture(pin, sCaptureWave);
	xvi_capture_.init(sCaptureWave,num_samples);
	xvi_capture=xvi_capture_;	

	return;
}

#ifdef AFX_SDSP_H_INCLUDED


CSC_STATUS xvi_read_capture(short pin, int site, Csdsp *sdsp_ptr, WF & s_wave, char * wf_name, const int & data_type)	
{
	
	int			num_samples;
	sdouble_wf	sCaptureWave;
	CSC_STATUS	ret_status;

	BOOL local_active_site[MAX_SITES];
	int i;

	
	for(i=0; i<max_sites; i++)
	{
		local_active_site[i] = active_site[i];
		if(i!=site) active_site[i]=false;
	}

	

	num_samples=xvi_read_capture(pin, sCaptureWave);	
	MSDOUBLE_WF MsCaptureWave(sCaptureWave,num_samples);

	ret_status=MsCaptureWave.copy_to(sdsp_ptr, site, s_wave, wf_name, data_type);

	
	for(i=0; i<max_sites; i++)
		active_site[i]=local_active_site[i];

	return ret_status;
}
#endif 

#endif	





MSFLOAT_WF::MSFLOAT_WF(float **s_float_wf, int size)
{
	
	
	ms_ext_data = true;
	ms_ary_size = size;
	ms_id		= MS_FLOAT;
	ms_array	= s_float_wf;
}

MSDOUBLE_WF::MSDOUBLE_WF(double **s_double_wf, int size)
{
	
	
	ms_ext_data = true;
	ms_ary_size = size;
	ms_id		= MS_DOUBLE;
	ms_array	= s_double_wf;
}

void MSFLOAT_WF::init(float **s_float_wf, int size)
{
#if 1
	
	int site=0;
	int sample=0;
	
	if((ms_ary_size != size)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		
		for (site=0; site < CSC_LAST_SITE; site++)
			ms_array[site]=new float[size];
	}

	if(ms_array==NULL)
	{
		
		ms_array=new float* [CSC_LAST_SITE];

		
		for (site=0; site < CSC_LAST_SITE; site++)
			ms_array[site]=new float[size];
	}

	
	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < size; sample++)
			ms_array[site][sample]=s_float_wf[site][sample];
		
	ms_ext_data	= false;		
	ms_id		= MS_FLOAT;
	ms_ary_size = size;

#else
	
	int site=0;

	
	
	if((!ms_ext_data)&&(ms_array!=NULL))	
	{
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		if(ms_array!=NULL)
			delete[] ms_array;
	}

	ms_ext_data = true;
	ms_ary_size = size;
	ms_id		= MS_FLOAT;
	ms_array	= s_float_wf;
#endif
}

void MSDOUBLE_WF::init(double **s_double_wf, int size)
{
#if 1
	
	int site=0;
	int sample=0;
	
	if((ms_ary_size != size)&&(ms_array!=NULL))
	{
		
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		
		for (site=0; site < CSC_LAST_SITE; site++)
			ms_array[site]=new double[size];
	}
	
	if(ms_array==NULL)
	{
		
		ms_array=new double* [CSC_LAST_SITE];

		
		for (site=0; site < CSC_LAST_SITE; site++)
			ms_array[site]=new double[size];
	}

	
	for (site=0; site < CSC_LAST_SITE; site++) if(IS_SITE_ACTIVE)
		for (sample=0; sample < size; sample++)
			ms_array[site][sample]=s_double_wf[site][sample];
		
	ms_ext_data	= false;		
	ms_id		= MS_DOUBLE;
	ms_ary_size = size;

#else
	
	int site=0;

	
	
	if((!ms_ext_data)&&(ms_array!=NULL))	
	{
		for (site=0; site < CSC_LAST_SITE; site++)
			if(ms_array[site]!=NULL)
				delete[] ms_array[site];

		if(ms_array!=NULL)
			delete[] ms_array;
	}

	ms_ext_data = true;
	ms_ary_size = size;
	ms_id		= MS_DOUBLE;
	ms_array	= s_double_wf;
#endif
}

template <class arrType> 

MS_Number<arrType> _mean(MS_Array<arrType> MS_Ary)	
{
	return MS_Ary.Mean();
}

MS_Number<double> ms_mean (MS_Array<double> MS_Ary) {return _mean <double>(MS_Ary);}

MS_Number<float> ms_mean (MS_Array<float> MS_Ary) {return _mean <float>(MS_Ary);}	
MS_Number<double> ms_mean (MSDOUBLE_WF MS_Ary) {return _mean <double>(MS_Ary);}	
MS_Number<float> ms_mean (MSFLOAT_WF MS_Ary) {return _mean <float>(MS_Ary);}	

template <class arrType> 

MS_Number<arrType> _rms(MS_Array<arrType> MS_Ary)	
{
	return MS_Ary.Rms();
}

MS_Number<double> ms_rms (MS_Array<double> MS_Ary) {return _rms <double>(MS_Ary);}

MS_Number<float> ms_rms (MS_Array<float> MS_Ary) {return _rms <float>(MS_Ary);}	
MS_Number<double> ms_rms (MSDOUBLE_WF MS_Ary) {return _rms <double>(MS_Ary);}	
MS_Number<float> ms_rms (MSFLOAT_WF MS_Ary) {return _rms <float>(MS_Ary);}	

template <class arrType> 

MS_Number<arrType> _min(MS_Array<arrType> MS_Ary)	
{
	return MS_Ary.Min();
}

MS_Number<double> ms_min (MS_Array<double> MS_Ary) {return _min <double>(MS_Ary);}

MS_Number<float> ms_min (MS_Array<float> MS_Ary) {return _min <float>(MS_Ary);}	
MS_Number<double> ms_min (MSDOUBLE_WF MS_Ary) {return _min <double>(MS_Ary);}	
MS_Number<float> ms_min (MSFLOAT_WF MS_Ary) {return _min <float>(MS_Ary);}	

template <class arrType> 

MS_Number<arrType> _max(MS_Array<arrType> MS_Ary)	
{
	return MS_Ary.Max();
}

MS_Number<double> ms_max (MS_Array<double> MS_Ary) {return _max <double>(MS_Ary);}

MS_Number<float> ms_max (MS_Array<float> MS_Ary) {return _max <float>(MS_Ary);}	
MS_Number<double> ms_max (MSDOUBLE_WF MS_Ary) {return _max <double>(MS_Ary);}	
MS_Number<float> ms_max (MSFLOAT_WF MS_Ary) {return _max <float>(MS_Ary);}	

template <class arrType> 

void _mean_stdev_rms(MS_Array<arrType> MS_Ary, MS_Number<arrType> &Mean, MS_Number<arrType> &Stdev, MS_Number<arrType> &Rms, int Start, int Stop)
{
	MS_Ary.mean_stdev_rms(Mean, Stdev, Rms, Start, Stop);
}



	
void mean_stdev_rms (MS_Array<double> MS_Ary, MS_Number<double> &Mean, MS_Number<double> &Stdev, MS_Number<double> &Rms, int Start=-1, int Stop=-1) {_mean_stdev_rms<double>(MS_Ary, Mean, Stdev, Rms, Start, Stop);}	
void mean_stdev_rms (MS_Array<float> MS_Ary, MS_Number<float> &Mean, MS_Number<float> &Stdev, MS_Number<float> &Rms, int Start=-1, int Stop=-1) {_mean_stdev_rms<float>(MS_Ary, Mean, Stdev, Rms, Start, Stop);}		
void mean_stdev_rms (MSDOUBLE_WF MS_Ary, MSDOUBLE &Mean, MSDOUBLE &Stdev, MSDOUBLE &Rms, int Start=-1, int Stop=-1) {_mean_stdev_rms<double>(MS_Ary, Mean, Stdev, Rms, Start, Stop);}		
void mean_stdev_rms (MSFLOAT_WF MS_Ary, MSFLOAT &Mean, MSFLOAT &Stdev, MSFLOAT &Rms, int Start=-1, int Stop=-1) {_mean_stdev_rms<float>(MS_Ary, Mean, Stdev, Rms, Start, Stop);}			

template <class arrType> 

void _min_max_idx(MS_Array<arrType> MS_Ary, MS_Number<arrType> &Min, MS_Number<arrType> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx, int Start, int Stop)	
{
	MS_Ary.min_max_idx(Min, Max, MinIdx, MaxIdx, Start, Stop);
}




void min_max_idx (MS_Array<double> MS_Ary, MS_Number<double> &Min, MS_Number<double> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx, int Start=-1, int Stop=-1) {_min_max_idx<double>(MS_Ary, Min, Max, MinIdx, MaxIdx, Start, Stop);}	
void min_max_idx (MS_Array<float> MS_Ary, MS_Number<float> &Min, MS_Number<float> &Max, MS_Number<int> &MinIdx, MS_Number<int> &MaxIdx, int Start=-1, int Stop=-1) {_min_max_idx<float>(MS_Ary, Min, Max, MinIdx, MaxIdx, Start, Stop);}		
void min_max_idx (MSDOUBLE_WF MS_Ary, MSDOUBLE &Min, MSDOUBLE &Max, MSINT &MinIdx, MSINT &MaxIdx, int Start=-1, int Stop=-1) {_min_max_idx<double>(MS_Ary, Min, Max, MinIdx, MaxIdx, Start, Stop);}		
void min_max_idx (MSFLOAT_WF MS_Ary, MSFLOAT &Min, MSFLOAT &Max, MSINT &MinIdx, MSINT &MaxIdx, int Start=-1, int Stop=-1) {_min_max_idx<float>(MS_Ary, Min, Max, MinIdx, MaxIdx, Start, Stop);}			

#ifdef AFX_SDSP_H_INCLUDED

CSC_STATUS MSDOUBLE_WF::copy_to(Csdsp *sdsp_ptr, int site, WF & s_wave, char * wf_name, const int & data_type)	
{
	CSC_STATUS stat;
	
	stat=sdsp_ptr->array_to_wf (1, ms_ary_size, data_type, ms_array[site], wf_name, &s_wave);
	return stat;
}
CSC_STATUS MSFLOAT_WF::copy_to(Csdsp *sdsp_ptr, int site, WF & s_wave, char * wf_name, const int & data_type)	
{
	CSC_STATUS stat;
	double *temp_double_ptr;
	int i;

	temp_double_ptr = new double[ms_ary_size];
	for(i=0; i<ms_ary_size; i++)
		temp_double_ptr[i]=(double)ms_array[site][i];

	
	stat=sdsp_ptr->array_to_wf (1, ms_ary_size, data_type, temp_double_ptr, wf_name, &s_wave);

	delete temp_double_ptr;
	return stat;
}
#endif	


void zap_word_select_lzb(MSFLOAT trim_value, MSUINT &zap_word, float *weight_list, unsigned int *word_list, int list_lenght, MSUINT &idx)
{
	sfloat	_trim_value;
	suint	_zap_word;
	suint	_idx;

	trim_value.copy_to(_trim_value);
	zap_word_select_lzb(_trim_value, _zap_word, weight_list, word_list, list_lenght, _idx);
	zap_word=_zap_word;

	if(idx[0]>=0)
		idx=_idx;
}

void zap_word_select_lzb(MSDOUBLE trim_value, MSUINT &zap_word, float *weight_list, unsigned int *word_list, int list_lenght, MSUINT &idx)
{
	sfloat	_trim_value;
	suint	_zap_word;
	suint	_idx;

	trim_value.copy_to(_trim_value);
	zap_word_select_lzb(_trim_value, _zap_word, weight_list, word_list, list_lenght, _idx);
	zap_word=_zap_word;

	if(idx[0]>=0)
		idx=_idx;
}

void store_site_status(SITE_STATUS &usr_active_site)
{
	sint	_usr_active_site;

	store_site_status(_usr_active_site);
	usr_active_site=_usr_active_site;
}

void store_site_status(MSBOOL &usr_active_site)
{
	sint	_usr_active_site;

	store_site_status(_usr_active_site);
	usr_active_site=_usr_active_site;
}

void restore_site_status(SITE_STATUS usr_active_site)
{
	sint	_usr_active_site;
	int		site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		if(usr_active_site[site])
			_usr_active_site[site]=1;
		else
			_usr_active_site[site]=0;

	restore_site_status(_usr_active_site);
}

void restore_site_status(MSBOOL usr_active_site)
{
	sint	_usr_active_site;
	int		site=0;

	for (site=0; site < CSC_LAST_SITE; site++)
		if(usr_active_site[site])
			_usr_active_site[site]=1;
		else
			_usr_active_site[site]=0;

	restore_site_status(_usr_active_site);
}

sint	IfBlockCondSiteBuffer;	
sint	IfBlockSiteBuffer[255];	
int		IfBlockStackIdx=0;		


#endif	
