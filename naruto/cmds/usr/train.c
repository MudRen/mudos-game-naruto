/* train.c 訓練技能指令 by -Acme- */

inherit F_CLEAN_UP;

int do_train(object me, object trainer, string skill, int count)
{
	if( !objectp(me) || !objectp(trainer) ) return notify_fail("這裡沒有這個人。\n");
	
    // 不是訓練師
	if( !trainer->is_trainer() ) return notify_fail("這個人似乎不想教你。\n");
	
    // 如果是在區域環境中，不同座標，不會有動作
	if( environment(me)->is_area() )
		if( !area_environment(me, trainer) ) return notify_fail("這裡沒有這個人。\n");

    // all: 不分忍者村, 否則看是否相同的忍者村
    if( trainer->query("guild") != "all" &&  trainer->query("guild") != me->query("guild") )
        return notify_fail("對方似乎不想教你。\n");
	
	return trainer->train_skill(me, skill, count);
}

int main(object me, string arg)
{
	int count;
	object trainer;
	string skill, who;
	
	if( !arg ) return notify_fail("你想向誰討教並訓練你的技能？\n");
	
    if( me->query_condition("weak") ) return notify_fail("你現在的狀況無法學習技能。\n");

	if( sscanf(arg, "%s from %s for %d", skill, who, count) == 3 ) {
        if( !objectp(trainer = present(who, environment(me))) )
            return notify_fail("你的附近沒有這個人。\n");
	} else if( sscanf(arg, "%s from %s", skill, who) == 2 ) {
        if( !objectp(trainer = present(who, environment(me))) )
            return notify_fail("你的附近沒有這個人。\n");
		count = 1;
	}

    if( count <= 0 ) count = 1;

    return do_train(me, trainer, skill, count);
}

int help()
{
    write(@TEXT
指令格式﹕train <技能名稱> from <人物> [for <次數>]

這個指令可以向某人討教並訓練你的技能，不過對方願不願意教你，
並不是你可以決定的。一般人是不會輕易的教導別人武功，就算是願
意教導，也通常不會傾囊相授。
TEXT);
    return 1;
}
