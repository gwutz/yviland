bin_PROGRAMS = yviland
yviland_SOURCES = main.vala \
		    game.vala \
		    gamestate.vala \
			camera.vala \
		    texturemanager.vala \
			fontmanager.vala \
		    states/testlevel.vala \
			components/animationcomponent.vala \
			components/collisioncomponent.vala \
			components/movementcomponent.vala \
			components/positioncomponent.vala \
			components/rendercomponent.vala \
			components/tilemapcomponent.vala \
			components/tilemapcomponent2.vala \
			components/cameracomponent.vala \
			components/resourcecomponent.vala \
			components/textcomponent.vala \
			systems/rendersystem.vala \
			systems/tilemaprendersystem.vala \
			systems/texturesystem.vala \
			systems/movementsystem.vala \
			systems/animationsystem.vala \
			systems/collisionsystem.vala \
			systems/resourceloadersystem.vala \
			systems/textrendersystem.vala \
		    $(NULL)
yviland_VALAFLAGS = \
		--pkg sdl2 \
		--pkg sdl2-image \
		--pkg sdl2-ttf \
		--pkg gee-0.8 \
		--pkg gxml-0.10 \
		--pkg tiled \
		--pkg config \
		--pkg engine \
		--vapidir $(top_srcdir)/tmx \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/engine \
		$(NULL)

yviland_CFLAGS = -O4 $(YVILAND_CFLAGS) -I$(top_srcdir)/tmx -DPACKAGE_DATADIR=\"$(pkgdatadir)\" -I$(top_srcdir)/engine
yviland_LDADD = $(YVILAND_LIBS) $(top_builddir)/tmx/libtiled.la $(top_builddir)/engine/libengine.la
