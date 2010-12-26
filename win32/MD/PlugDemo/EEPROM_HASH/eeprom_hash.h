
		#ifndef __eeprom_table__h
		#define __eeprom_table__h
		/*EEPROM HASHTABLE for SuperMD plugin*/
		/*Generated by Conle's eeprom hash generator(source included in package)*/
		/*(no std::hash map for C compatibility)*/
		/*original String table by GenplusGX authors*/
		static const unsigned int EEPROM_HASHTABLE[] = {
		/*24C01*/
		 2651326343,1272246362,1272320991,1272321696,1272318807,
		1272319785,1566572451,1566572353,3629835479,3629835449,
		1201268073,3600839954,1215143474,2525469675,152579897,
		955312248,
		/*24C02*/
		 3123025847,2710133793,2710138180,3123032757,
		/*24C08 ( same as 24C16 00000000-00 game )*/
		 351473998,
		/*24C16*/
		 3123048386,
		/*24C65*/
		 2710137245,2710137535,2896233196
		};
		 
		static const unsigned int EEPROM_HASHTABLE_LENGTH = sizeof(EEPROM_HASHTABLE) / sizeof(EEPROM_HASHTABLE[0]);
		#endif //__eeprom_table__h