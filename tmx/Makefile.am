noinst_LTLIBRARIES = libtiled.la

NULL =

BUILT_SOURCES = tiled.vala.stamp

AM_CPPFLAGS = \
	$(TILED_CFLAGS) \
	$(NULL)

libtiled_la_VALASOURCES = \
	data.vala \
	image.vala \
	layer.vala \
	map.vala \
	object.vala \
	objectgroup.vala \
	tile.vala \
	tiled.vala \
	tileset.vala \
	$(NULL)

libtiled_la_SOURCES = \
	tiled.vala.stamp \
	$(libtiled_la_VALASOURCES:.vala=.c) \
	$(NULL)

VALAFLAGS = --pkg gxml-0.10 --pkg sdl2

tiled.vapi tiled.vala.stamp: $(libtiled_la_VALASOURCES)
	$(VALAC) \
		$(VALAFLAGS) \
		-C \
		--library tiled \
		-H tiled.h \
		$^
	@touch $@

libtiled_la_LIBADD = \
	$(TILED_LIBS) \
	$(NULL)
