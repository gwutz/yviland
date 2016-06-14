-include $(top_srcdir)/git.mk

bin_PROGRAMS = yviland
yviland_SOURCES = main.vala \
		    animationcomponent.vala \
		    collisioncomponent.vala \
		    component.vala \
		    entity.vala \
		    game.vala \
		    gamestate.vala \
		    movementcomponent.vala \
		    positioncomponent.vala \
		    rendercomponent.vala \
		    texturemanager.vala \
		    tilemapcomponent.vala \
		    states/testlevel.vala \
				cameracomponent.vala \
				gravitycomponent.vala \
		    $(NULL)
yviland_VALAFLAGS = \
		--pkg sdl2 \
		--pkg sdl2-image \
		--pkg gee-0.8 \
		--pkg gxml-0.10 \
		--pkg tiled \
		--pkg config \
		--vapidir $(top_srcdir)/tmx \
		--vapidir $(top_srcdir)/vapi \
		--define=DEBUG \
		$(NULL)

yviland_CFLAGS = $(YVILAND_CFLAGS) -I$(top_srcdir)/tmx -DPACKAGE_DATADIR=\"$(pkgdatadir)\"
yviland_LDADD = $(YVILAND_LIBS) $(top_builddir)/tmx/libtiled.la
