// armor.h

#ifndef __ARMOR_H__
#define __ARMOR_H__

/*
      �Y�G �Y��(F_HEAD_EQ)  �y��(F_MASK_EQ)    �V��(F_NECK_EQ)    => ����, �U�l, ����
    ����G ��A(F_CLOTH)    �Z��(F_CLOTH)      �y��(F_WAIST_EQ)   => �Z��, ��A, �y�a
      ��G ��x(F_HAND_EQ)  ���(F_FINGER_EQ)  ���(F_WRIST_EQ)   => ��M, �٫�, �@��
      �}�G �Ǥl(F_PANTS)    �}�x(F_FEET_EQ)    �p�L(F_LEG_EQ)     => �Ǥl, �c�l, �j�L
 */
#define F_HEAD_EQ   "/feature/armor/head_eq.c"
#define F_FACE_EQ   "/feature/armor/face_eq.c"
#define F_NECK_EQ   "/feature/armor/neck_eq.c"

#define F_CLOTH     "/feature/armor/cloth.c"
#define F_ARMOR     "/feature/armor/armor.c"
#define F_WAIST_EQ  "/feature/armor/waist_eq.c"

#define F_HAND_EQ   "/feature/armor/hand_eq.c"
#define F_FINGER_EQ "/feature/armor/finger_eq.c"
#define F_WRIST_EQ  "/feature/armor/wrist_eq.c"

#define F_PANTS     "/feature/armor/pants.c"
#define F_FEET_EQ   "/feature/armor/feet_eq.c"
#define F_LEG_EQ    "/feature/armor/leg_eq.c"
	
#ifndef __WEAPON_H__
//inherit COMBINED_ITEM;
inherit ITEM;
inherit F_ATTRIBUTE;
inherit F_EQUIP;
inherit F_STATISTIC;
#endif

#endif