noinst_LTLIBRARIES = libengine.la

NULL =

BUILT_SOURCES = engine.vala.stamp

AM_CPPFLAGS = \
	$(ENGINE_CFLAGS) \
	$(NULL)

libengine_la_VALASOURCES = \
	engine.vala \
	entity.vala \
	entitymanager.vala \
	entitysystem.vala \
	systemmanager.vala \
	component.vala \
	$(NULL)

libengine_la_SOURCES = \
	engine.vala.stamp \
	$(libengine_la_VALASOURCES:.vala=.c) \
	$(NULL)

VALAFLAGS = --pkg sdl2 --pkg gee-0.8

envine.vapi engine.vala.stamp: $(libengine_la_VALASOURCES)
	$(VALAC) \
		$(VALAFLAGS) \
		-C \
		--library engine \
		-H engine.h \
		$^
	@touch $@

libengine_la_LIBADD = \
	$(ENGINE_LIBS) \
	$(NULL)
