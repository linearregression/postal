/* mongo-source.h
 *
 * Copyright (C) 2012 Christian Hergert <chris@dronelabs.com>
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MONGO_SOURCE_H
#define MONGO_SOURCE_H

#include <gio/gio.h>

G_BEGIN_DECLS

/**
 * MongoSource:
 *
 * #MongoSource is a #GSource for completing asynchronous mongo requests.
 * It can be attached to a given #GMainContext so that requests complete
 * in a particular thread.
 *
 * Typically, you would use #MongoClient:async-context to specify the
 * thread you want to complete requests within and #MongoClient with use
 * #MongoSource to ensure they are completed there.
 */
typedef struct _MongoSource MongoSource;

MongoSource *mongo_source_new              (void);
void         mongo_source_complete_in_idle (MongoSource        *source,
                                            GSimpleAsyncResult *simple);

void mongo_simple_async_result_complete_in_idle (GSimpleAsyncResult *simple);

G_END_DECLS

#endif /* MONGO_SOURCE_H */
