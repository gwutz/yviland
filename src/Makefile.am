-include $(top_srcdir)/git.mk

bin_PROGRAMS = yviland
yviland_SOURCES = main.vala \
		    components/animationcomponent.vala \
		    components/collisioncomponent.vala \
		    game.vala \
		    gamestate.vala \
		    components/movementcomponent.vala \
		    components/positioncomponent.vala \
		    components/rendercomponent.vala \
		    texturemanager.vala \
		    components/tilemapcomponent.vala \
				components/tilemapcomponent2.vala \
		    states/testlevel.vala \
				components/cameracomponent.vala \
				components/gravitycomponent.vala \
				systems/rendersystem.vala \
				systems/tilemaprendersystem.vala \
				camera.vala \
		    $(NULL)
yviland_VALAFLAGS = \
		--pkg sdl2 \
		--pkg sdl2-image \
		--pkg gee-0.8 \
		--pkg gxml-0.10 \
		--pkg tiled \
		--pkg config \
		--pkg engine \
		--vapidir $(top_srcdir)/tmx \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/engine \
		--define=DEBUG \
		-g \
		$(NULL)

yviland_CFLAGS = $(YVILAND_CFLAGS) -I$(top_srcdir)/tmx -DPACKAGE_DATADIR=\"$(pkgdatadir)\" -I$(top_srcdir)/engine
yviland_LDADD = $(YVILAND_LIBS) $(top_builddir)/tmx/libtiled.la $(top_builddir)/engine/libengine.la
