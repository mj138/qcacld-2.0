/*
 * Copyright (c) 2011-2014 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/**
 * @file ol_tx.h
 * @brief Internal definitions for the high-level tx module.
 */
#ifndef _OL_TX__H_
#define _OL_TX__H_

#include <adf_nbuf.h>    /* adf_nbuf_t */
#include <adf_os_lock.h>
#include <ol_txrx_api.h> /* ol_txrx_vdev_handle */

#include <ol_txrx_types.h>  /* ol_tx_desc_t, ol_txrx_msdu_info_t */

adf_nbuf_t
ol_tx_ll(ol_txrx_vdev_handle vdev, adf_nbuf_t msdu_list);

adf_nbuf_t
ol_tx_ll_queue(ol_txrx_vdev_handle vdev, adf_nbuf_t msdu_list);

#ifdef QCA_SUPPORT_TXRX_VDEV_LL_TXQ
#define OL_TX_LL ol_tx_ll_queue
#else
#define OL_TX_LL ol_tx_ll
#endif

void ol_tx_vdev_ll_pause_queue_send(void *context);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0))
void ol_tx_vdev_ll_pause_queue_timer(struct timer_list* t);
#endif

adf_nbuf_t
ol_tx_non_std_ll(
    ol_txrx_vdev_handle data_vdev,
    enum ol_tx_spec tx_spec,
    adf_nbuf_t msdu_list);

adf_nbuf_t
ol_tx_hl(ol_txrx_vdev_handle vdev, adf_nbuf_t msdu_list);

adf_nbuf_t
ol_tx_non_std_hl(
    ol_txrx_vdev_handle data_vdev,
    enum ol_tx_spec tx_spec,
    adf_nbuf_t msdu_list);

adf_nbuf_t
ol_tx_reinject(struct ol_txrx_vdev_t *vdev, adf_nbuf_t msdu, u_int16_t peer_id);

void
ol_txrx_mgmt_tx_complete(void *ctxt, adf_nbuf_t netbuf, int err);

void
ol_tx_pdev_ll_pause_queue_send_all(struct ol_txrx_pdev_t *pdev);
#endif /* _OL_TX__H_ */
