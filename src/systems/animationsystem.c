/* animationsystem.c generated by valac 0.32.0, the Vala compiler
 * generated from animationsystem.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <engine.h>
#include <float.h>
#include <math.h>
#include <gee.h>


#define TYPE_ANIMATION_SYSTEM (animation_system_get_type ())
#define ANIMATION_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ANIMATION_SYSTEM, AnimationSystem))
#define ANIMATION_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ANIMATION_SYSTEM, AnimationSystemClass))
#define IS_ANIMATION_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ANIMATION_SYSTEM))
#define IS_ANIMATION_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ANIMATION_SYSTEM))
#define ANIMATION_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ANIMATION_SYSTEM, AnimationSystemClass))

typedef struct _AnimationSystem AnimationSystem;
typedef struct _AnimationSystemClass AnimationSystemClass;
typedef struct _AnimationSystemPrivate AnimationSystemPrivate;

#define TYPE_ANIMATION_COMPONENT (animation_component_get_type ())
#define ANIMATION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ANIMATION_COMPONENT, AnimationComponent))
#define ANIMATION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ANIMATION_COMPONENT, AnimationComponentClass))
#define IS_ANIMATION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ANIMATION_COMPONENT))
#define IS_ANIMATION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ANIMATION_COMPONENT))
#define ANIMATION_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ANIMATION_COMPONENT, AnimationComponentClass))

typedef struct _AnimationComponent AnimationComponent;
typedef struct _AnimationComponentClass AnimationComponentClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _AnimationSystem {
	EngineEntitySystem parent_instance;
	AnimationSystemPrivate * priv;
};

struct _AnimationSystemClass {
	EngineEntitySystemClass parent_class;
};


static gpointer animation_system_parent_class = NULL;

GType animation_system_get_type (void) G_GNUC_CONST;
enum  {
	ANIMATION_SYSTEM_DUMMY_PROPERTY
};
static GType* animation_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1);
GType animation_component_get_type (void) G_GNUC_CONST;
static void animation_system_real_update (EngineSystem* base, gfloat deltaTime);
gboolean animation_component_next_animation (AnimationComponent* self);
AnimationSystem* animation_system_new (void);
AnimationSystem* animation_system_construct (GType object_type);


static GType* animation_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1) {
	AnimationSystem * self;
	GType* result = NULL;
	GType* _tmp0_ = NULL;
	GType* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	self = (AnimationSystem*) base;
	_tmp0_ = g_new0 (GType, 1);
	_tmp0_[0] = TYPE_ANIMATION_COMPONENT;
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 1;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void animation_system_real_update (EngineSystem* base, gfloat deltaTime) {
	AnimationSystem * self;
	self = (AnimationSystem*) base;
	{
		GeeList* _e_list = NULL;
		GeeList* _tmp0_ = NULL;
		GeeList* _tmp1_ = NULL;
		gint _e_size = 0;
		GeeList* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _e_index = 0;
		_tmp0_ = ((EngineEntitySystem*) self)->entities;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_e_list = _tmp1_;
		_tmp2_ = _e_list;
		_tmp3_ = gee_collection_get_size ((GeeCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_e_size = _tmp4_;
		_e_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			EngineEntity* e = NULL;
			GeeList* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			AnimationComponent* ani = NULL;
			EngineEntity* _tmp11_ = NULL;
			gpointer _tmp12_ = NULL;
			AnimationComponent* _tmp13_ = NULL;
			gboolean _tmp14_ = FALSE;
			_tmp5_ = _e_index;
			_e_index = _tmp5_ + 1;
			_tmp6_ = _e_index;
			_tmp7_ = _e_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _e_list;
			_tmp9_ = _e_index;
			_tmp10_ = gee_list_get (_tmp8_, _tmp9_);
			e = (EngineEntity*) _tmp10_;
			_tmp11_ = e;
			_tmp12_ = engine_entity_get_component (_tmp11_, TYPE_ANIMATION_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
			ani = (AnimationComponent*) _tmp12_;
			_tmp13_ = ani;
			_tmp14_ = animation_component_next_animation (_tmp13_);
			if (_tmp14_) {
				EngineEngine* _tmp15_ = NULL;
				EngineEntity* _tmp16_ = NULL;
				_tmp15_ = ((EngineSystem*) self)->engine;
				_tmp16_ = e;
				engine_engine_removeEntity (_tmp15_, _tmp16_);
			}
			_g_object_unref0 (ani);
			_g_object_unref0 (e);
		}
		_g_object_unref0 (_e_list);
	}
}


AnimationSystem* animation_system_construct (GType object_type) {
	AnimationSystem * self = NULL;
	self = (AnimationSystem*) engine_entity_system_construct (object_type);
	return self;
}


AnimationSystem* animation_system_new (void) {
	return animation_system_construct (TYPE_ANIMATION_SYSTEM);
}


static void animation_system_class_init (AnimationSystemClass * klass) {
	animation_system_parent_class = g_type_class_peek_parent (klass);
	((EngineEntitySystemClass *) klass)->getEntityTypes = animation_system_real_getEntityTypes;
	((EngineSystemClass *) klass)->update = animation_system_real_update;
}


static void animation_system_instance_init (AnimationSystem * self) {
}


GType animation_system_get_type (void) {
	static volatile gsize animation_system_type_id__volatile = 0;
	if (g_once_init_enter (&animation_system_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AnimationSystemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) animation_system_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AnimationSystem), 0, (GInstanceInitFunc) animation_system_instance_init, NULL };
		GType animation_system_type_id;
		animation_system_type_id = g_type_register_static (ENGINE_TYPE_ENTITY_SYSTEM, "AnimationSystem", &g_define_type_info, 0);
		g_once_init_leave (&animation_system_type_id__volatile, animation_system_type_id);
	}
	return animation_system_type_id__volatile;
}


