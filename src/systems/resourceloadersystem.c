/* resourceloadersystem.c generated by valac 0.32.0, the Vala compiler
 * generated from resourceloadersystem.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <engine.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_RESOURCE_LOADER_SYSTEM (resource_loader_system_get_type ())
#define RESOURCE_LOADER_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_RESOURCE_LOADER_SYSTEM, ResourceLoaderSystem))
#define RESOURCE_LOADER_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_RESOURCE_LOADER_SYSTEM, ResourceLoaderSystemClass))
#define IS_RESOURCE_LOADER_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_RESOURCE_LOADER_SYSTEM))
#define IS_RESOURCE_LOADER_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_RESOURCE_LOADER_SYSTEM))
#define RESOURCE_LOADER_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_RESOURCE_LOADER_SYSTEM, ResourceLoaderSystemClass))

typedef struct _ResourceLoaderSystem ResourceLoaderSystem;
typedef struct _ResourceLoaderSystemClass ResourceLoaderSystemClass;
typedef struct _ResourceLoaderSystemPrivate ResourceLoaderSystemPrivate;

#define TYPE_FONT_MANAGER (font_manager_get_type ())
#define FONT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FONT_MANAGER, FontManager))
#define FONT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FONT_MANAGER, FontManagerClass))
#define IS_FONT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FONT_MANAGER))
#define IS_FONT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FONT_MANAGER))
#define FONT_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FONT_MANAGER, FontManagerClass))

typedef struct _FontManager FontManager;
typedef struct _FontManagerClass FontManagerClass;

#define TYPE_RESOURCE_COMPONENT (resource_component_get_type ())
#define RESOURCE_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_RESOURCE_COMPONENT, ResourceComponent))
#define RESOURCE_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_RESOURCE_COMPONENT, ResourceComponentClass))
#define IS_RESOURCE_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_RESOURCE_COMPONENT))
#define IS_RESOURCE_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_RESOURCE_COMPONENT))
#define RESOURCE_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_RESOURCE_COMPONENT, ResourceComponentClass))

typedef struct _ResourceComponent ResourceComponent;
typedef struct _ResourceComponentClass ResourceComponentClass;
typedef struct _ResourceComponentPrivate ResourceComponentPrivate;

#define RESOURCE_COMPONENT_TYPE_RESOURCE_TYPE (resource_component_resource_type_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _ResourceLoaderSystem {
	EngineIteratingEntitySystem parent_instance;
	ResourceLoaderSystemPrivate * priv;
};

struct _ResourceLoaderSystemClass {
	EngineIteratingEntitySystemClass parent_class;
};

struct _ResourceLoaderSystemPrivate {
	FontManager* fontManager;
};

typedef enum  {
	RESOURCE_COMPONENT_RESOURCE_TYPE_FONT
} ResourceComponentResourceType;

struct _ResourceComponent {
	EngineComponent parent_instance;
	ResourceComponentPrivate * priv;
	ResourceComponentResourceType type;
	gchar* identifier;
	gchar* filename;
	gint ptsize;
};

struct _ResourceComponentClass {
	EngineComponentClass parent_class;
};


static gpointer resource_loader_system_parent_class = NULL;

GType resource_loader_system_get_type (void) G_GNUC_CONST;
GType font_manager_get_type (void) G_GNUC_CONST;
#define RESOURCE_LOADER_SYSTEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_RESOURCE_LOADER_SYSTEM, ResourceLoaderSystemPrivate))
enum  {
	RESOURCE_LOADER_SYSTEM_DUMMY_PROPERTY
};
ResourceLoaderSystem* resource_loader_system_new (FontManager* fontManager);
ResourceLoaderSystem* resource_loader_system_construct (GType object_type, FontManager* fontManager);
static GType* resource_loader_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1);
GType resource_component_get_type (void) G_GNUC_CONST;
static void resource_loader_system_real_processEntity (EngineIteratingEntitySystem* base, gfloat deltaTime, EngineEntity* e);
GType resource_component_resource_type_get_type (void) G_GNUC_CONST;
gboolean font_manager_loaded (FontManager* self, const gchar* identifier);
void font_manager_load (FontManager* self, const gchar* identifier, const gchar* filename, gint ptsize);
static void resource_loader_system_finalize (GObject* obj);


ResourceLoaderSystem* resource_loader_system_construct (GType object_type, FontManager* fontManager) {
	ResourceLoaderSystem * self = NULL;
	FontManager* _tmp0_ = NULL;
	g_return_val_if_fail (fontManager != NULL, NULL);
	self = (ResourceLoaderSystem*) engine_iterating_entity_system_construct (object_type);
	_tmp0_ = fontManager;
	self->priv->fontManager = _tmp0_;
	return self;
}


ResourceLoaderSystem* resource_loader_system_new (FontManager* fontManager) {
	return resource_loader_system_construct (TYPE_RESOURCE_LOADER_SYSTEM, fontManager);
}


static GType* resource_loader_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1) {
	ResourceLoaderSystem * self;
	GType* result = NULL;
	GType* _tmp0_ = NULL;
	GType* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	self = (ResourceLoaderSystem*) base;
	_tmp0_ = g_new0 (GType, 1);
	_tmp0_[0] = TYPE_RESOURCE_COMPONENT;
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 1;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static void resource_loader_system_real_processEntity (EngineIteratingEntitySystem* base, gfloat deltaTime, EngineEntity* e) {
	ResourceLoaderSystem * self;
	ResourceComponent* resource = NULL;
	EngineEntity* _tmp0_ = NULL;
	gpointer _tmp1_ = NULL;
	ResourceComponentResourceType _tmp2_ = 0;
	self = (ResourceLoaderSystem*) base;
	g_return_if_fail (e != NULL);
	_tmp0_ = e;
	_tmp1_ = engine_entity_get_component (_tmp0_, TYPE_RESOURCE_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	resource = (ResourceComponent*) _tmp1_;
	_tmp2_ = resource->type;
	switch (_tmp2_) {
		case RESOURCE_COMPONENT_RESOURCE_TYPE_FONT:
		{
			FontManager* _tmp3_ = NULL;
			const gchar* _tmp4_ = NULL;
			gboolean _tmp5_ = FALSE;
			_tmp3_ = self->priv->fontManager;
			_tmp4_ = resource->identifier;
			_tmp5_ = font_manager_loaded (_tmp3_, _tmp4_);
			if (!_tmp5_) {
				FontManager* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				gint _tmp9_ = 0;
				_tmp6_ = self->priv->fontManager;
				_tmp7_ = resource->identifier;
				_tmp8_ = resource->filename;
				_tmp9_ = resource->ptsize;
				font_manager_load (_tmp6_, _tmp7_, _tmp8_, _tmp9_);
			}
			break;
		}
		default:
		break;
	}
	_g_object_unref0 (resource);
}


static void resource_loader_system_class_init (ResourceLoaderSystemClass * klass) {
	resource_loader_system_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ResourceLoaderSystemPrivate));
	((EngineEntitySystemClass *) klass)->getEntityTypes = resource_loader_system_real_getEntityTypes;
	((EngineIteratingEntitySystemClass *) klass)->processEntity = resource_loader_system_real_processEntity;
	G_OBJECT_CLASS (klass)->finalize = resource_loader_system_finalize;
}


static void resource_loader_system_instance_init (ResourceLoaderSystem * self) {
	self->priv = RESOURCE_LOADER_SYSTEM_GET_PRIVATE (self);
}


static void resource_loader_system_finalize (GObject* obj) {
	ResourceLoaderSystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_RESOURCE_LOADER_SYSTEM, ResourceLoaderSystem);
	G_OBJECT_CLASS (resource_loader_system_parent_class)->finalize (obj);
}


GType resource_loader_system_get_type (void) {
	static volatile gsize resource_loader_system_type_id__volatile = 0;
	if (g_once_init_enter (&resource_loader_system_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ResourceLoaderSystemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) resource_loader_system_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ResourceLoaderSystem), 0, (GInstanceInitFunc) resource_loader_system_instance_init, NULL };
		GType resource_loader_system_type_id;
		resource_loader_system_type_id = g_type_register_static (ENGINE_TYPE_ITERATING_ENTITY_SYSTEM, "ResourceLoaderSystem", &g_define_type_info, 0);
		g_once_init_leave (&resource_loader_system_type_id__volatile, resource_loader_system_type_id);
	}
	return resource_loader_system_type_id__volatile;
}


