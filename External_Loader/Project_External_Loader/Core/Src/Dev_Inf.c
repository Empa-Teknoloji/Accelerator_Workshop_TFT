/*
 * Dev_Inf.c
 *
 */
#include "Dev_Inf.h"
#include "mx25l6433f.h"

/* This structure contains information used by ST-LINK Utility to program and erase the device */
#if defined(__ICCARM__)
__root struct StorageInfo const StorageInfo = {
#else
struct StorageInfo __attribute__((section(".Dev_info"))) /*const*/ StorageInfo = {
#endif
    "STM32G0B1RE-Ext-Loader", // Device Name + version number
    SPI_FLASH,                // Device Type
    0x90000000,               // Device Start Address
    sFLASH_SPI_FLASH_SIZE,    // Device Size in Bytes
    sFLASH_SPI_PAGE_SIZE,     // Programming Page Size
    0xFF,                     // Initial Content of Erased Memory
    // Specify Size and Address of Sectors (view example below)
    {{(sFLASH_SPI_FLASH_SIZE / sFLASH_SPI_SECTOR_SIZE), // Sector Numbers,
      (uint32_t)sFLASH_SPI_SECTOR_SIZE},                // Sector Size

     {0x00000000, 0x00000000}}};
