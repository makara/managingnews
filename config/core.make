core = "6.x"
api = "2"

projects[drupal][type] = "core"
projects[drupal][version] = "6.22"

; Openatrium
projects[drupal][patch][openatrium] = "http://drupalcode.org/project/openatrium.git/blob_plain/refs/tags/6.x-1.0-beta10:/robots_txt_rollback.patch"
