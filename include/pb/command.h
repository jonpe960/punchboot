/**
 * Punch BOOT
 *
 * Copyright (C) 2018 Jonas Blixt <jonpe960@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef INCLUDE_PB_RECOVERY_H_
#define INCLUDE_PB_RECOVERY_H_

#include <stdint.h>
#include <stdbool.h>
#include <pb/storage.h>
#include <pb/transport.h>
#include <pb/crypto.h>
#include <pb-tools/wire.h>
#include <bpak/bpak.h>

struct pb_command_context
{
    struct pb_storage *storage;
    struct pb_transport *transport;
    struct pb_crypto *crypto;
    struct bpak_keystore *keystore;
    bool authenticated;
    void *buffer;
    size_t buffer_size;
    int no_of_buffers;
    struct pb_storage_driver *stream_drv;
    struct pb_storage_map *stream_map;
    size_t stream_offset;
    struct pb_hash_context hash_ctx;
    struct pb_result result;
};

int pb_command_parse(struct pb_command_context *ctx, struct pb_command *cmd);

int pb_command_init(struct pb_command_context *command,
                  struct pb_transport *transport,
                  struct pb_storage *storage,
                  struct pb_crypto *crypto,
                  struct bpak_keystore *keystore);

#endif  // INCLUDE_PB_RECOVERY_H_
