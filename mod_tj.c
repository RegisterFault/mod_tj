#include <stdio.h>
#include "apr_hash.h"
#include "ap_config.h"
#include "ap_provider.h"
#include "httpd.h"
#include "http_core.h"
#include "http_config.h"
#include "http_log.h"
#include "http_protocol.h"
#include "http_request.h"


static int tj_handler(request_rec *r)
{
        if(!r->handler || strcmp(r->handler, "tj-handler")) return (DECLINED);

        ap_set_content_type(r, "text/html");
        ap_rprintf(r, "Hello, World!");

        return OK;
}

static void tj_register_hooks(apr_pool_t *pool)
{
        ap_hook_handler(tj_handler, NULL, NULL, APR_HOOK_LAST);
}

AP_DECLARE_MODULE(tj) = {
        STANDARD20_MODULE_STUFF,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        tj_register_hooks,
};
