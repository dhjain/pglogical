/*-------------------------------------------------------------------------
 *
 * pg_logical_output.h
 *		pg_logical output plugin
 *
 * Copyright (c) 2015, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *		pg_logical_output.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_LOGICAL_OUTPUT_H
#define PG_LOGICAL_OUTPUT_H

#include "nodes/parsenodes.h"

#include "replication/logical.h"
#include "replication/output_plugin.h"

#include "storage/lock.h"

#define PG_LOGICAL_PROTO_VERSION_NUM 1
#define PG_LOGICAL_PROTO_MIN_VERSION_NUM 1

typedef struct
{
	MemoryContext context;

	bool allow_binary_protocol;
	bool allow_sendrecv_protocol;
	bool int_datetime_match;
	bool forward_changesets;

	const char *client_encoding;
	uint32 client_pg_version;
	uint32 client_pg_catversion;
	uint32 client_proto_version;
	uint32 client_min_proto_version;
} PGLogicalOutputData;

typedef struct PGLogicalTupleData
{
	Datum	values[MaxTupleAttributeNumber];
	bool	nulls[MaxTupleAttributeNumber];
	bool	changed[MaxTupleAttributeNumber];
} PGLogicalTupleData;


#endif /* PG_LOGICAL_OUTPUT_H */