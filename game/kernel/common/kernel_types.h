#pragma once

#include "common/common_types.h"

//! Mirror of cpad-info
#pragma pack(push, 1)
struct CPadInfo {
  u8 valid;
  u8 status;
  u16 button0;
  u8 rightx;
  u8 righty;
  u8 leftx;
  u8 lefty;
  u8 abutton[12];
  u8 dummy[12];
  s32 number;
  s32 cpad_file;
  u32 button0_abs[3];
  u32 button0_shadow_abs[1];
  u32 button0_rel[3];
  float stick0_dir;
  float stick0_speed;
  s32 new_pad;
  s32 state;
  u8 align[6];
  u8 direct[6];
  u8 buzz_val[2];
  u8 buzz_pause_val[1];
  u8 buzz_pause_time;
  u64 buzz_time[2];
  u32 buzz;
  s32 buzz_act;
  s64 change_time;  // actually u64 in goal!
};
// static_assert(offsetof(CPadInfo, number) == 32, "CPadInfo number field is wrong");
static_assert(sizeof(CPadInfo) == 132, "CPadInfo size is wrong");
#pragma pack(pop)

struct FileStream {
  u32 flags;
  u32 mode;  // basic
  u32 name;  // basic
  s32 file;  // int32
};

struct HnsPlayerInfo {
  u32 role;  // mp-game-role enum
  u32 mp_state;  // mp-tgt-state enum
  s32 collected_by_pnum;
  s32 rank;
};

const int MAX_USERNAME_LEN = 100;
struct RemotePlayerInfo {
  u32 username; // string (basic)
  u32 color;  // tgt-color enum
  s32 is_admin; // 0 or 1 (idk how to write #t/#f from c++ side)
  float trans_x;
  float trans_y;
  float trans_z;
  float quat_x;
  float quat_y;
  float quat_z;
  float quat_w;
  s32 tgt_state;
  HnsPlayerInfo hns_info;
  float cam_trans_x;
  float cam_trans_y;
  float cam_trans_z;
  float cam_trans_w;
  float cam_rot_1;
  float cam_rot_2;
  float cam_rot_3;
  float cam_rot_4;
  float cam_rot_5;
  float cam_rot_6;
  float cam_rot_7;
  float cam_rot_8;
  float cam_rot_9;
};
// static_assert(sizeof(RemotePlayerInfo) == 32, "RemotePlayerInfo size is wrong");

struct HideAndSeekGameInfoStruct {
  // admin-driven settings
  u32 target_hider_type;
  u32 level_mode;
  u32 continue_point_mode;
  s32 hiders_move;  // 0 or 1 (idk how to write #t/#f from c++ side)
  s32 hiders_pause_zoom;  // 0 or 1 (idk how to write #t/#f from c++ side)
  s32 seekers_infect;     // 0 or 1 (idk how to write #t/#f from c++ side)
  s32 num_seekers;
  s32 last_winner_as_seeker;  // 0 or 1 (idk how to write #t/#f from c++ side)
  float fog_distance;
  float hider_speed;
  float seeker_speed;
  s32 time_to_start;
  s32 time_to_hide;
  s32 hider_victory_timeout;
  s32 post_game_timeout;
  // server-driven fields
  s32 alert_found_pnum;
  s32 alert_seeker_pnum;
  s32 num_hiders;
  s32 num_hiders_left;
};

const int MAX_MULTIPLAYER_COUNT = 12;

struct MultiplayerInfo {
  s32 game_type_mode;
  s32 player_num;
  s32 lobby_name;
  RemotePlayerInfo players[MAX_MULTIPLAYER_COUNT];
  HideAndSeekGameInfoStruct hide_and_seek_game_info;
  u32 state; // mp-game-state enum
};
//static_assert(sizeof(MultiplayerInfo) == 116, "MultiplayerInfo size is wrong");