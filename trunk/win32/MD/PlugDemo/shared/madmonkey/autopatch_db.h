#ifndef autopatch_db_h
#define autopatch_db_h

#define KB 1024
#define MB (KB*KB)
#define Kb (KB/8)
#define Mb (MB/8)
#define PATCH_BUFFER_ENTRIES (8)

typedef unsigned char MD5Buf[16];
typedef struct patch_data patch_data;
typedef struct auto_patch_entry auto_patch_entry;

enum
{
	DUMP_TYPE_SMS = 0,
	DUMP_TYPE_MD,
	DUMP_TYPE_32X,
	DUMP_TYPE_SCDBIOS,
	DUMP_TYPE_SCDSYS
};

struct sms_save_entry
{
	MD5Buf md5;
	short unitsof8K;
};

struct patch_data
{
    int offset;
    unsigned short value;
};

struct auto_patch_entry
{
	int type;
    MD5Buf md5;
    patch_data patch[PATCH_BUFFER_ENTRIES];
};

static const sms_save_entry sms_save_table[]= //remember MD MYTH PROGRAMMER EXPECTS 8K UNITS
{
    {
        {0x8f,0xe5,0x5a,0xde,0x7b,0x34,0xaa,0x4e,0x42,0xc5,0xf6,0x3f,0x43,0x68,0x49,0x7f},
        1
    },
    {
        {0xff,0x75,0x02,0xdd,0x8a,0x71,0x7d,0xb5,0xad,0xb4,0x2c,0x71,0x1d,0xdb,0xc9,0xf5},
        1
    },
    {
        {0xd4,0x6e,0x40,0xbb,0xb7,0x29,0xba,0x23,0x3f,0x17,0x1a,0xd7,0xbf,0x61,0x69,0xf5},
        1
    },
    {
        {0x1f,0xa3,0x30,0xa1,0x7d,0xf1,0x98,0x20,0xf4,0xc8,0xe0,0x23,0x0d,0x3c,0xfb,0xe2},
        1
    },
    {
        {0x55,0x54,0xf9,0xf6,0x71,0x03,0xe0,0xd5,0xb1,0xa4,0x07,0x5a,0x2d,0x26,0xd1,0x5b},
        1
    },
    {
        {0x8d,0xde,0xc5,0x89,0xf7,0x2c,0xdc,0xf2,0xcd,0x4c,0xaa,0xfb,0x07,0x5e,0xc8,0xe4},
        1
    },
    {
        {0x1b,0x69,0x71,0x6f,0x9f,0x40,0x53,0xe1,0x53,0x3f,0x65,0x4c,0x09,0x1a,0xe4,0x10},
        1
    },
    {
        {0xa0,0xf6,0x14,0xf2,0x6e,0x99,0x63,0x34,0x93,0xe3,0xa3,0x33,0x9b,0xc8,0x55,0x86},
        1
    },
    {
        {0xdf,0xeb,0xc4,0x8d,0xfe,0x81,0x65,0x20,0x2b,0x7f,0x00,0x2d,0x8b,0xac,0x47,0x7b},
        1
    },
    {
        {0xf8,0x53,0xb7,0xdd,0xca,0x63,0x86,0x47,0x35,0xc0,0x30,0x01,0xc9,0xac,0x47,0x7b},
        1
    },
    {
        {0x35,0x9a,0xe4,0xa1,0x69,0x3e,0x99,0x6d,0x42,0x19,0xb9,0x26,0x95,0x41,0xc7,0x6b},
        1
    },
    {
        {0x5b,0xa9,0x11,0x4e,0xde,0xa5,0xde,0xb5,0x28,0x2f,0xd9,0xad,0x7d,0x4b,0x2d,0x62},
        1
    },
    {
        {0xce,0x2c,0x9a,0xae,0x1f,0x48,0xaf,0x31,0x0e,0x57,0x67,0x43,0x67,0x35,0xec,0xfe},
        1
    },
    {
        {0x11,0x10,0x93,0x8d,0xf8,0x0f,0x4e,0x44,0xc8,0x21,0x3d,0x7f,0x85,0xcf,0xb5,0xe6},
        1
    },
    {
        {0xd9,0x2b,0x72,0xc8,0x71,0x79,0xb7,0x18,0xc8,0xb1,0x50,0x6b,0x34,0x7c,0x2e,0x36},
        1
    },
    {
        {0xc5,0x4c,0x1a,0x25,0x59,0xce,0xc1,0x89,0xf5,0x3e,0x79,0x41,0x77,0xd0,0x02,0xaf},
        1
    },
    {
        {0x17,0x36,0x41,0x62,0xda,0x3c,0xce,0xe8,0x47,0x85,0x0d,0xd9,0xb4,0x03,0x76,0x5c},
        1
    },
    {
        {0xdd,0x5d,0x01,0xd4,0xe1,0xfe,0x7d,0x27,0x5f,0x95,0xac,0x95,0xdc,0x63,0xb0,0x4f},
        1
    },
    {
        {0x77,0xd2,0xff,0x05,0x44,0x29,0xf7,0x97,0x01,0x34,0xe6,0x78,0x00,0x53,0x9a,0x78},
        1
    }
};

static const auto_patch_entry auto_patch_table[]= 
{
//scd_bios
    {
		DUMP_TYPE_SCDBIOS,
        {0xbd,0xeb,0x4c,0x47,0xda,0x61,0x39,0x46,0xd4,0x22,0xd9,0x7d,0x98,0xb2,0x1c,0xda},
        {{0x722,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x27,0x8a,0x93,0x97,0xd1,0x92,0x14,0x9e,0x84,0xe8,0x20,0xac,0x62,0x1a,0x8e,0xdd},
        {{0x720,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xe6,0x6f,0xa1,0xdc,0x58,0x20,0xd2,0x54,0x61,0x1f,0xdc,0xdb,0xa0,0x66,0x23,0x72},
        {{0x7c8,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x2e,0xfd,0x74,0xe3,0x23,0x2f,0xf2,0x60,0xe3,0x71,0xb9,0x9f,0x84,0x02,0x4f,0x7f},
        {{0x7c2,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x68,0x3a,0x8a,0x9e,0x27,0x36,0x62,0x56,0x11,0x72,0x46,0x8d,0xfa,0x28,0x58,0xeb},
        {{0x72c,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x9b,0x56,0x2e,0xbf,0x2d,0x09,0x5b,0xf1,0xda,0xba,0xdb,0xc1,0x88,0x1f,0x51,0x9a},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xb1,0x0c,0x0a,0x97,0xab,0xc5,0x7b,0x75,0x84,0x97,0xd3,0xfa,0xe6,0xab,0x35,0xa4},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xec,0xc8,0x37,0xc3,0x1d,0x77,0xb7,0x74,0xc6,0xe2,0x7e,0x38,0xf8,0x28,0xaa,0x9a},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x85,0x4b,0x91,0x50,0x24,0x0a,0x19,0x80,0x70,0x15,0x0e,0x45,0x66,0xae,0x12,0x90},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xba,0xca,0x1d,0xf2,0x71,0xd7,0xc1,0x1f,0xe5,0x00,0x87,0xc0,0x35,0x8f,0x4e,0xb5},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xae,0x52,0xba,0xd8,0xad,0x2e,0xf4,0x83,0xd8,0x7f,0xb4,0x72,0xe5,0x21,0x29,0x4d},
        {{0x7ae,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0xa5,0xa2,0xf9,0xaa,0xe5,0x7d,0x46,0x4b,0xc6,0x6b,0x80,0xee,0x79,0xc3,0xda,0x6e},
        {{0x84a,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x69,0x1c,0x3f,0xd3,0x68,0x21,0x12,0x80,0xd2,0x68,0x64,0x5c,0x0e,0xfd,0x2e,0xff},
        {{0x84a,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x0e,0x73,0x93,0xcd,0x09,0x51,0xd6,0xdd,0xe8,0x18,0xfc,0xd4,0xcd,0x81,0x94,0x66},
        {{0x84a,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x73,0x2b,0x60,0x96,0x02,0x26,0xca,0xf3,0x3d,0xf6,0xb4,0x87,0xf3,0x76,0xde,0x69},
        {{0x720,0x4e75},{-1}}
    },
    {
		DUMP_TYPE_SCDBIOS,
        {0x82,0xce,0x23,0x63,0xf7,0xdd,0xc6,0x20,0xb9,0xc2,0x55,0xd3,0x58,0x33,0x11,0x8f},
        {{0x84a,0x4e75},{-1}}
    },
    {// http://arakon.dyndns.org/
		DUMP_TYPE_SCDBIOS,
        {0x16,0x97,0x9d,0x13,0x37,0x7c,0x1b,0xbb,0xbf,0xa9,0x51,0xdd,0xa5,0x6d,0xdf,0xd6},
        {{-1}}
    },
//md_rom
    {
		DUMP_TYPE_MD,
        {0x75,0x95,0x0e,0x3a,0xa9,0x35,0x7a,0x21,0x71,0x5f,0xfe,0x2f,0xa5,0x1a,0x45,0x4c},
        {{0x1f0,0x5520},{0x3bdc,0x605e},{-1}}
    },
    {
		DUMP_TYPE_MD,
        {0x48,0x90,0xfe,0x7d,0xbb,0xed,0x12,0xd7,0xdb,0x1e,0xf0,0x29,0xca,0x7d,0x93,0x0a},
        {{0x3be6,0x6060},{0x63fa,0x6042},{-1}}
    },
    {
		DUMP_TYPE_MD,
        {0x82,0x5e,0x67,0x79,0x7b,0xfc,0xf3,0xc2,0x77,0x54,0xd5,0x9b,0x4f,0x66,0x84,0x93},
        {{0x1f0,0x5520},{0x3bdc,0x605e},{-1}}
    },
};

static const int auto_patch_table_size=sizeof(auto_patch_table)/sizeof(auto_patch_entry);
static const int sms_save_table_size=sizeof(sms_save_table)/sizeof(sms_save_entry);

#endif

