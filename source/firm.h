#pragma once

#include <stdint.h>
#include <stddef.h>

#include "headers.h"
#include "firm_signatures.h"

#include "3dsheaders.h"

extern firm_h *firm_orig_loc;
extern size_t firm_size;
extern struct firm_signature *current_firm;
extern firm_h *twl_firm_orig_loc;
extern size_t twl_firm_size;
extern struct firm_signature *current_twl_firm;
extern firm_h *agb_firm_orig_loc;
extern size_t agb_firm_size;
extern struct firm_signature *current_agb_firm;
extern int save_firm;

struct firm_signature *get_firm_info(firm_h *firm, struct firm_signature *signatures, enum firm_types firm_type);
void slot0x11key96_init();
int load_firms();
void boot_firm();
void boot_cfw();

u32 loadNintendoFirm(FirmwareType *firmType, FirmwareSource nandType, bool loadFromStorage, bool isSafeMode);
void loadHomebrewFirm(u32 pressed);
u32 patchNativeFirm(u32 firmVersion, FirmwareSource nandType, bool loadFromStorage, bool isFirmProtEnabled, bool needToInitSd, bool doUnitinfoPatch);
u32 patchTwlFirm(u32 firmVersion, bool loadFromStorage, bool doUnitinfoPatch);
u32 patchAgbFirm(bool loadFromStorage, bool doUnitinfoPatch);
u32 patch1x2xNativeAndSafeFirm(void);
void launchFirm(int argc, char **argv);
