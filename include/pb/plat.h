/**
 * Punch BOOT
 *
 * Copyright (C) 2020 Jonas Blixt <jonpe960@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef INCLUDE_PB_PLAT_H_
#define INCLUDE_PB_PLAT_H_

#include <pb/pb.h>
#include <pb/usb.h>
#include <pb/fuse.h>
#include <pb/crypto.h>
#include <pb/storage.h>
#include <pb/boot.h>
#include <pb/board.h>
#include <pb/fuse.h>
#include <bpak/keystore.h>
#include <uuid/uuid.h>
#include <pb-tools/wire.h>

/* Platform API Calls */
void plat_reset(void);
void plat_wdog_init(void);
void plat_wdog_kick(void);

int plat_early_init(void);
int plat_late_init(void);
void plat_preboot_cleanup(void);
bool plat_force_command_mode(void);
int plat_get_uuid(char *out);
int plat_patch_bootargs(void *fdt, int offset, bool verbose_boot);
int plat_boot_override(uint8_t *uuid);

int plat_early_boot(void);
int plat_late_boot(bool *abort_boot, bool manual);

int plat_command(uint32_t command,
                     void *bfr,
                     size_t size,
                     void *response_bfr,
                     size_t *response_size);

int plat_status(void *response_bfr,
                    size_t *response_size);
/* Console API */
int plat_console_init(void);
int plat_console_putchar(char c);

/* Fusebox API */
int plat_fuse_read(struct fuse *f);
int plat_fuse_write(struct fuse *f);
int plat_fuse_to_string(struct fuse *f, char *s, uint32_t n);

/* Security Life Cycle (SLC) API */
int plat_slc_init(void);
int plat_slc_set_configuration(void);
int plat_slc_set_configuration_lock(void);
int plat_slc_set_end_of_life(void);
int plat_slc_read(enum pb_slc *slc);
int plat_slc_key_active(uint32_t id, bool *active);
int plat_slc_revoke_key(uint32_t id);
int plat_slc_get_key_status(struct pb_result_slc_key_status **status);

/* Crypto API */
int plat_crypto_init(void);
int plat_hash_init(struct pb_hash_context *ctx, enum pb_hash_algs alg);
int plat_hash_update(struct pb_hash_context *ctx, void *buf, size_t size);
int plat_hash_finalize(struct pb_hash_context *ctx, void *buf, size_t size);
int plat_pk_verify(void *signature, size_t size, struct pb_hash_context *hash,
                        struct bpak_key *key);

/* Transport API */
int plat_transport_init(void);
int plat_transport_process(void);
bool plat_transport_ready(void);
int plat_transport_write(void *buf, size_t size);
int plat_transport_read(void *buf, size_t size);


#endif  // INCLUDE_PB_PLAT_H_
