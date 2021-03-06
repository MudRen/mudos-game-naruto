#include <login.h> 
inherit ITEM;

void create()
{
    set_name("神行石", ({ "jump stone","stone"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "塊");
        set("value", 0);
        set("long", "一塊小石頭，上面泛著神秘的光芒\n好像只有巫師們才知道用途。");
    }
    setup();
}

void init()
{
    add_action("do_move", "move");
}

int do_move(string arg)
{

   switch(arg) {
      case "wizard": this_player()->move("/world/area/wizard/guildhall.c");break;
      case "muye": this_player()->move("/world/area/muye/inn.c");break;
      case "wild": this_player()->move("/world/area/wild/house.c");break;
      default: break;
   }

   return 1;
}
