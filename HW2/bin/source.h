#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "bin/env.h"
#include "bin/help.h"
#include "bin/listdir.h"
#include "bin/quit.h"
#include "bin/forking.h"
#include "bin/cp.h" 
#include "bin/dupe.h"
#include "bin/setargs.h"
#include "bin/isQC.h"
#include "bin/printDir.h"
#include "bin/Iter.h"
#include "bin/comparestr.h"
#include "bin/inp.h"
#include "bin/iscmd.h"
#include "bin/jobs.h"
#include "bin/set.h"
#include "bin/noinp.h"
#include "bin/runQC.h"
#include "bin/parentProcess.h"
#include "bin/readInOpen.h"
#include "bin/pipecnt.h"
#include "bin/readOutOpen.h"
#include "bin/pline.h"