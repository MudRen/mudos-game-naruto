
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"好人卡"NOR"-"HIG"加強版"NOR, ({ "super nice guy card", "card" }));

    set_weight(1);

    if( !clonep() ) {
        set("base_unit", "張");
        set("base_value", 978);
        set("base_weight", 1);
        set("long", 
@LONG
╭──┬───────┬──╮
│０95│  好人的証明  │D-40│
├──┴───────┴──┤
│�歈����������������������腡x
│��      你是好人，可是..�齰x
│�齯ㄜn說了啊啊啊啊∼    �齰x
│��  <○>         ○~    �齰x
│��    \         /▲\    �齰x
│��    /＼        ||     �齰x
│��                      �齰x
│�裺����������������������憓x
├─────────────┤
│ 在大膽表白後常有的結局， │
│ 可說是集合了許多人的怨念 │
｜ ，使得天下忠厚老實的人越 ｜
│ 來越少....               │
╰─────────────╯
LONG);
    }
    setup();

}
