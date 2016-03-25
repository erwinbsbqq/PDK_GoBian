
const unsigned char ali_sflash_deviceid_table[] =
{
//ENDIAN_LITTLE	
//  device_id_byte,   (dev_id_idx<<5)|right_shfit_bits
	0x04, 8,/*0*/ /* AT26F004 */
	0x45, 8,/*1*/ /* AT26DF081 */
	0x46, 8,/*2*/ /* AT26DF161 */
	0x47, 8,/*3*/ /* AT26DF321 */
	0x13, 24,/*4*/ /* A25L40P */
	0x14, 24,/*5*/ /* A25L80P */
	0x15, 24,/*6*/ /* A25L16P */
	0x32, 56,/*7*/ /* EN25B40B */
	0x42, 56,/*8*/ /* EN25B40T */
	0x33, 56,/*9*/ /* EN25B80B */
	0x43, 56,/*10*/ /* EN25B80T */
	0x34, 56,/*11*/ /* EN25B16B */
	0x44, 56,/*12*/ /* EN25B16T */	
	0x8D, 16,/*13*/ /* SST25VF040B */				
	0x8E, 16,/*14*/ /* SST25VF080B */
	0x41, 16,/*15*/ /* SST25VF016B */
	0x4A, 16,/*16*/ /* SST25VF032B */
	0x4B, 16,/*17*/ /* SST25VF064C */
/*18*/	0x01, 16,	/* SST26VF016 */
/*19*/	0x02, 16,	/* SST26VF032 */
	//The following should go after all others
/*20*/	0x12, 56,	/* EN25P40 */ /* M25P40 M25PE40 M45PE40*/  /* MX25L4005A */  /* S25FL004A */ /*W25X40*/
/*21*/	0x13, 56,	/* EN25P80 */ /* M25P80 M25PE80 M45PE80*/  /* MX25L8005 */   /* S25FL008A */ /*W25X80*/
/*22*/	0x14, 56,	/* EN25P16 */ /* M25P16 M25PE16 M45PE16 */ /* MX25L1605/A */ /* S25FL016A */ /*W25X16*/
/*23*/	0x15, 56,   /* M25P32 */ /* MX25L3205/A */ /* S25FL032A */ /*W25X32*/ /*ESMT F25L32PA*/
/*24*/	0x11, 16,       /*intel S33 2MB*/
/*25*/	0x31, 8,        /*EoN 16CN20C*/
/*26*/	0x8c, 24,       /*ESMT*/
/*27*/	0x16, 56,	/*MX25L6405D*//*S25FL064A*/ /*W25X64*/
/*28*/	0x17, 56,	/*MX25L12845E*/
/*29*/	0x15, 16,		/* MX25L1635D*/
/*30*/	0x16, 16,		/* MX25L3235D*/
/*31*/	0x20, 0,	/*M25128P*/
/*32*/	0x35, 56, /*EN25B32B */
/*33*/	0x12, 16,       /*intel S33 4MB*/
/*34*/	0x48, 8,	/* AT25DF641 */
/*35*/	0x36, 56,	/* EN25B64 */
/*36*/   	0x26 , 8, /*MX25L6455E*/
};

/*Restrictly mapped with sflash_deviceid_table with same array index.*/
/* Index of tflash_sectors and flash_sector_begin*/
const unsigned char ali_sflash_sector_struct_idx[] =
{
	7, 13, 14, 17,					/* start from index 0*/
	24, 26, 28, 					/* start from index 4*/
	24, 25, 26, 27, 28, 29,			/* start from index 7*/
	7, 13, 14, 17, 31,				/* start from index 13*/
	35, 36,  						/* start from 18*/
	7, 13, 14, 17,30,13, 13, 31, 34, 30, 17, 32,		/* start from 20*/
	33, 17, 31, 37,					/* start from index 32*/
	38,							/* start from index 36*/
	
};

const unsigned short ali_sflash_deviceid_num = \
	(sizeof(ali_sflash_deviceid_table) / (2 * sizeof(unsigned char))) ;


