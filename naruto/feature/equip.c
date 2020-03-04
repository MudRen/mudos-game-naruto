// �˳� equip.c

#include <ansi.h>
#include <combat.h>
#include <dbase.h>
#include <name.h>
#include <move.h>
#include <type.h>

private void apply(mapping a)
{
    string prop;
    mixed app;
    mapping applied;

    applied = environment()->query_temp("apply");
    if( !mapp(applied) ) applied = ([]);

    foreach(prop, app in a) {
        switch(typeof(app)) {
        case INT:
        case FLOAT:
            applied[prop] += app;
            break;
        case ARRAY:
        case MAPPING:
        case OBJECT:
        case STRING:
            if( undefinedp(applied[prop]) ) applied[prop] = ({ app });
            else if( arrayp(applied[prop]) ) applied[prop] += ({ app });
            else error("Incompatible equipment apply.\n");
            break;
        default:
            error("Illegal type of equipment apply.\n");
            break;
        }
    }
}

private void unapply(mapping a)
{
    string prop;
    mixed app;
    mapping applied;

    applied = environment()->query_temp("apply");
    if( !mapp(applied) ) applied = ([]);

    foreach(prop, app in a) {
        switch(typeof(app)) {
        case INT:
        case FLOAT:
            applied[prop] -= app;
            break;
        case ARRAY:
        case MAPPING:
        case OBJECT:
        case STRING:
            if( !arrayp(applied[prop]) )
                error("Unconsistent type of apply encountered when attempt to unapply.\n");
            applied[prop] -= ({ app });
            break;
        default:
            error("Illegal type of equipment apply.\n");
            break;
        }
    }
}

int unequip()
{
    object owner;
    mapping prop, applied_prop;
    string *apply, equipped, type;

    if( !(owner = environment())->is_character() ) return 0;

    if( !stringp(equipped = query("equipped")) )
        return notify_fail("�A�ثe�èS���˳Ƴo�˪F��C\n");

    // This is a speed-generality concern hack.
    // Assume we wield this as 'sword', so we mark the wield in ourself
    // with set("equipped", "weapon/sword"), and call player->set_temp(
    // "weapon/sword", this_object(). Here the "weapon/sword" is the
    // equipped path in the database.
    owner->delete_temp(equipped);
    delete("equipped");

    if( mapp(prop = query("apply_" + equipped)) )
        unapply(prop);

    return 1;
}

varargs int wear(string on_part)
{
    object owner, old;
    mapping armor_prop;
    string *apply;
    mixed valid_types;

    // Only character object can wear armors.
    if( !(owner = environment())->is_character() ) return 0;

    // If already equipped in another usage, unequip first.
    if( query("equipped") && !unequip() ) return 0;

    // Check if this can be worn on some owner's body part.
    valid_types = query("wear_as");
    if( on_part ) {
        if( stringp(valid_types) ) {
            if(on_part != valid_types)
                return notify_fail("�o�˪F�褣��Q��@�o���@��ϥΡC\n");
        } else if( arrayp(valid_types) ) {
            if(member_array(on_part, valid_types)==-1)
                return notify_fail("�o�˪F�褣��Q��@�o���@��ϥΡC\n");
        } else 
            return notify_fail("�o�˪F�褣���@�@��C\n");
    } else {
        if( stringp(valid_types) ) on_part = valid_types;
        else if( arrayp(valid_types) ) on_part = valid_types[0];
        else return notify_fail("�o�˪F�褣���@�@��C\n");
    }

    // Ask race/class daemon to check if we can wield such weapon.
    notify_fail("�A���رک�¾�~�����\\�A�ϥγo���@��C\n");
    if( !(RACE_D(owner->query_race())->valid_wear(owner, this_object(), on_part)) ||
        !(CLASS_D(owner->query_class())->valid_wear(owner, this_object()), on_part))
        return 0;

    // if any object occupying on the same part, unequip it.
    if( old = owner->query_temp("armor/" + on_part) )
        if( !old->unequip() ) return 0;

    // Apply armor properties if any.
    if( mapp(armor_prop = query("apply_armor/" + on_part)) )
        apply(armor_prop);

    // okay, wear it.
    owner->set_temp("armor/" + on_part, this_object());
    set("equipped", "armor/" + on_part);

    return 1;
}

varargs int wield(string wield_as)
{
    object owner, old;
	mixed valid_types;
    mapping weapon_prop;
	
	if( !objectp(owner = environment()) || !owner->is_character() ) return 0;
	if( query("equipped") && !unequip() ) return 0;

    if( !wield_as ) wield_as = "righthand";

	valid_types = query("wield_as");

    if( stringp(valid_types) ) {
        if( wield_as != valid_types )
            return notify_fail("�o�˪F�褣��Q��@�o���Z���ϥΡC\n");
    } else if( arrayp(valid_types) ) {
	    if( member_array(wield_as, valid_types) == -1 )
		    return notify_fail("�o��Z���L�k�o�˨ϥΡC\n");
    } else return notify_fail("�o��Z���L�k�o�˨ϥΡC\n");
    
    if( wield_as == "twohanded" ) {
    	if( objectp(old = owner->query_temp("weapon/righthand")) )
    	    if( !old->unequip() ) return notify_fail("�A�L�k���U���b�ϥΤ����k��Z���C\n");
    	if( objectp(old = owner->query_temp("weapon/lefthand")) )
    	    if( !old->unequip() ) return notify_fail("�A�L�k���U���b�ϥΤ�������Z���C\n");
    	if( objectp(old = owner->query_temp("weapon/twohanded")) )
    		if( !old->unequip() ) return notify_fail("�A�L�k���U���b�ϥΤ��������Z���C\n");
    } else if( objectp(old = owner->query_temp("weapon/twohanded")) ) {
        if( !old->unequip() ) return notify_fail("�A�L�k���U���b�ϥΤ�������Z���C\n");
    } else if( objectp(old = owner->query_temp("weapon/" + wield_as)) ) 
        if( !old->unequip() ) return notify_fail("�A�L�k���U���b�ϥΤ����P�����Z���C\n");

/*
    if( !(RACE_D(owner->query_race())->valid_wield(owner, this_object(), wield_as)) ||
        !(CLASS_D(owner->query_class())->valid_wield(owner, this_object()), wield_as))
        return notify_fail("�A���رک�¾�~�����\\�A�ϥγo�تZ���C\n");
*/
    if( mapp(weapon_prop = query("apply_weapon/" + wield_as)) )
        apply(weapon_prop);

    owner->set_temp("weapon/" + wield_as, this_object());
    set("equipped", "weapon/" + wield_as);

    return 1;
}

// �Z���ˮ`�O��l��
void init_damage(int lower, int upper, int bonus, int level, string skill)
{
    set("damage/" + skill, ([ "lower": lower, "upper": upper, "bonus": bonus, "level": level, ]) );
    set("phase", PHASE_PHYSICAL);
}