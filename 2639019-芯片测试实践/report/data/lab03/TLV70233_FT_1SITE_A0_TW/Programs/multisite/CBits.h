




#define CBITSVER "1.2"

#if WINVER == 0x0501
	

#ifndef INC_CBITS		
#define INC_CBITS

class CSysPI_3K;  

#ifdef NT
    class BOARD_CLASS CBits	
    #else
    class CBits
    #endif
    {
    public:
		CBits();
		virtual ~CBits();
		
    	void			SetCbit(short cbitnum,bool val);
		unsigned short  GetCbit(short cbitnum);
		
    	
		
		void			set(short cbitnum,bool val);
		bool			get(short cbitnum);
		void 			init(void);
 
  	
  	

	private:
		CSysPI_3K * m_psyspi3k;
    };
#endif INC_CBITS		

#else
	

#ifndef INC_CBITS		
#define INC_CBITS

#ifdef NT
    class BOARD_CLASS CBits	
    #else
    class CBits
    #endif
    {
    public:
		
    	void			SetCbit(short cbitnum,bool val);
		unsigned short  GetCbit(short cbitnum);
		
    	
		
		void			set(short cbitnum,bool val);
		bool			get(short cbitnum);
		void 			init(void);

 
  
    };

#endif INC_CBITS		

#endif

