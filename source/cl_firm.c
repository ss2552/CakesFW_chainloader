#include "cl_types.h"
#include "cl_fs.h"

void loadHomebrewFirm(u32 pressed)
{
    char path[10 + 255];
    bool hasDisplayedMenu = false;
    bool found = !pressed ? payloadMenu(path, &hasDisplayedMenu) : findPayload(path, pressed);

    if(!found) return;

    u32 maxPayloadSize = (u32)((u8 *)0x27FFE000 - (u8 *)firm),
        payloadSize = fileRead(firm, path, maxPayloadSize);

    if(payloadSize <= 0x200 || !checkFirm(payloadSize)) error("The payload is invalid or corrupted.");

    char absPath[24 + 255];

    if(isSdMode) sprintf(absPath, "sdmc:/luma/%s", path);
    else sprintf(absPath, "nand:/rw/luma/%s", path);

    char *argv[2] = {absPath, (char *)fbs};
    bool wantsScreenInit = (firm->reserved2[0] & 1) != 0;

    if(!hasDisplayedMenu && wantsScreenInit)
        initScreens(); // Don't init the screens unless we have to, if not already done

    launchFirm(wantsScreenInit ? 2 : 1, argv);
}