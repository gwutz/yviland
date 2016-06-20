/* engine.c generated by valac 0.32.0, the Vala compiler
 * generated from engine.vala, do not modify */

/* TODO: Find a way to get efficient entities with specific components*/
/*       in an efficient way. Systems always need the same entities*/

#include <glib.h>
#include <glib-object.h>
#include <SDL2/SDL_pixels.h>
#include <gee.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define ENGINE_TYPE_STATE (engine_state_get_type ())

#define ENGINE_TYPE_ENGINE (engine_engine_get_type ())
#define ENGINE_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_ENGINE, EngineEngine))
#define ENGINE_ENGINE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_ENGINE, EngineEngineClass))
#define ENGINE_IS_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_ENGINE))
#define ENGINE_IS_ENGINE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_ENGINE))
#define ENGINE_ENGINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_ENGINE, EngineEngineClass))

typedef struct _EngineEngine EngineEngine;
typedef struct _EngineEngineClass EngineEngineClass;
typedef struct _EngineEnginePrivate EngineEnginePrivate;

#define ENGINE_TYPE_SYSTEM_MANAGER (engine_system_manager_get_type ())
#define ENGINE_SYSTEM_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_SYSTEM_MANAGER, EngineSystemManager))
#define ENGINE_SYSTEM_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_SYSTEM_MANAGER, EngineSystemManagerClass))
#define ENGINE_IS_SYSTEM_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_SYSTEM_MANAGER))
#define ENGINE_IS_SYSTEM_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_SYSTEM_MANAGER))
#define ENGINE_SYSTEM_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_SYSTEM_MANAGER, EngineSystemManagerClass))

typedef struct _EngineSystemManager EngineSystemManager;
typedef struct _EngineSystemManagerClass EngineSystemManagerClass;

#define ENGINE_TYPE_ENTITY_MANAGER (engine_entity_manager_get_type ())
#define ENGINE_ENTITY_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_ENTITY_MANAGER, EngineEntityManager))
#define ENGINE_ENTITY_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_ENTITY_MANAGER, EngineEntityManagerClass))
#define ENGINE_IS_ENTITY_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_ENTITY_MANAGER))
#define ENGINE_IS_ENTITY_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_ENTITY_MANAGER))
#define ENGINE_ENTITY_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_ENTITY_MANAGER, EngineEntityManagerClass))

typedef struct _EngineEntityManager EngineEntityManager;
typedef struct _EngineEntityManagerClass EngineEntityManagerClass;
#define _engine_system_manager_unref0(var) ((var == NULL) ? NULL : (var = (engine_system_manager_unref (var), NULL)))
#define _engine_entity_manager_unref0(var) ((var == NULL) ? NULL : (var = (engine_entity_manager_unref (var), NULL)))

#define ENGINE_TYPE_SYSTEM (engine_system_get_type ())
#define ENGINE_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_SYSTEM, EngineSystem))
#define ENGINE_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_SYSTEM, EngineSystemClass))
#define ENGINE_IS_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_SYSTEM))
#define ENGINE_IS_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_SYSTEM))
#define ENGINE_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_SYSTEM, EngineSystemClass))

typedef struct _EngineSystem EngineSystem;
typedef struct _EngineSystemClass EngineSystemClass;

#define ENGINE_TYPE_ENTITY_SYSTEM (engine_entity_system_get_type ())
#define ENGINE_ENTITY_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_ENTITY_SYSTEM, EngineEntitySystem))
#define ENGINE_ENTITY_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_ENTITY_SYSTEM, EngineEntitySystemClass))
#define ENGINE_IS_ENTITY_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_ENTITY_SYSTEM))
#define ENGINE_IS_ENTITY_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_ENTITY_SYSTEM))
#define ENGINE_ENTITY_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_ENTITY_SYSTEM, EngineEntitySystemClass))

typedef struct _EngineEntitySystem EngineEntitySystem;
typedef struct _EngineEntitySystemClass EngineEntitySystemClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define ENGINE_TYPE_ENTITY (engine_entity_get_type ())
#define ENGINE_ENTITY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_ENTITY, EngineEntity))
#define ENGINE_ENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_ENTITY, EngineEntityClass))
#define ENGINE_IS_ENTITY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_ENTITY))
#define ENGINE_IS_ENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_ENTITY))
#define ENGINE_ENTITY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_ENTITY, EngineEntityClass))

typedef struct _EngineEntity EngineEntity;
typedef struct _EngineEntityClass EngineEntityClass;
typedef struct _EngineParamSpecEngine EngineParamSpecEngine;

typedef enum  {
	ENGINE_STATE_PAUSED,
	ENGINE_STATE_RUNNING
} EngineState;

struct _EngineEngine {
	GTypeInstance parent_instance;
	volatile int ref_count;
	EngineEnginePrivate * priv;
	EngineState state;
};

struct _EngineEngineClass {
	GTypeClass parent_class;
	void (*finalize) (EngineEngine *self);
};

struct _EngineEnginePrivate {
	EngineSystemManager* systemManager;
	EngineEntityManager* entityManager;
	gboolean update_entities;
};

struct _EngineParamSpecEngine {
	GParamSpec parent_instance;
};


static gpointer engine_engine_parent_class = NULL;

GType engine_state_get_type (void) G_GNUC_CONST;
gpointer engine_engine_ref (gpointer instance);
void engine_engine_unref (gpointer instance);
GParamSpec* engine_param_spec_engine (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void engine_value_set_engine (GValue* value, gpointer v_object);
void engine_value_take_engine (GValue* value, gpointer v_object);
gpointer engine_value_get_engine (const GValue* value);
GType engine_engine_get_type (void) G_GNUC_CONST;
gpointer engine_system_manager_ref (gpointer instance);
void engine_system_manager_unref (gpointer instance);
GParamSpec* engine_param_spec_system_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void engine_value_set_system_manager (GValue* value, gpointer v_object);
void engine_value_take_system_manager (GValue* value, gpointer v_object);
gpointer engine_value_get_system_manager (const GValue* value);
GType engine_system_manager_get_type (void) G_GNUC_CONST;
gpointer engine_entity_manager_ref (gpointer instance);
void engine_entity_manager_unref (gpointer instance);
GParamSpec* engine_param_spec_entity_manager (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void engine_value_set_entity_manager (GValue* value, gpointer v_object);
void engine_value_take_entity_manager (GValue* value, gpointer v_object);
gpointer engine_value_get_entity_manager (const GValue* value);
GType engine_entity_manager_get_type (void) G_GNUC_CONST;
#define ENGINE_ENGINE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), ENGINE_TYPE_ENGINE, EngineEnginePrivate))
enum  {
	ENGINE_ENGINE_DUMMY_PROPERTY
};
EngineSystemManager* engine_system_manager_new (void);
EngineSystemManager* engine_system_manager_construct (GType object_type);
EngineEntityManager* engine_entity_manager_new (void);
EngineEntityManager* engine_entity_manager_construct (GType object_type);
GType engine_system_get_type (void) G_GNUC_CONST;
void engine_engine_addSystem (EngineEngine* self, EngineSystem* system);
void engine_system_manager_addSystem (EngineSystemManager* self, EngineSystem* system);
void engine_system_addedToEngine (EngineSystem* self, EngineEngine* engine);
void engine_engine_removeSystem (EngineEngine* self, EngineSystem* system);
void engine_system_manager_removeSystem (EngineSystemManager* self, EngineSystem* system);
void engine_system_removedFromEngine (EngineSystem* self, EngineEngine* engine);
void engine_engine_update (EngineEngine* self);
GeeList* engine_system_manager_getSystems (EngineSystemManager* self);
GType engine_entity_system_get_type (void) G_GNUC_CONST;
void engine_entity_system_updateEntities (EngineEntitySystem* self);
void engine_system_update (EngineSystem* self, gfloat deltaTime);
GType engine_entity_get_type (void) G_GNUC_CONST;
GeeList* engine_engine_getEntitiesFor (EngineEngine* self, GeeList* componenttypes);
GeeList* engine_entity_manager_getEntitiesFor (EngineEntityManager* self, GeeList* componenttypes);
EngineEntity* engine_engine_createEntity (EngineEngine* self);
EngineEntity* engine_entity_new (void);
EngineEntity* engine_entity_construct (GType object_type);
void engine_entity_manager_addEntity (EngineEntityManager* self, EngineEntity* entity);
void engine_engine_removeEntity (EngineEngine* self, EngineEntity* e);
void engine_entity_manager_removeEntity (EngineEntityManager* self, EngineEntity* entity);
EngineEngine* engine_engine_new (void);
EngineEngine* engine_engine_construct (GType object_type);
static void engine_engine_finalize (EngineEngine* obj);

const SDL_Color ENGINE_COLOR_BLACK = {(guint8) 0, (guint8) 0, (guint8) 0, (guint8) 255};

GType engine_state_get_type (void) {
	static volatile gsize engine_state_type_id__volatile = 0;
	if (g_once_init_enter (&engine_state_type_id__volatile)) {
		static const GEnumValue values[] = {{ENGINE_STATE_PAUSED, "ENGINE_STATE_PAUSED", "paused"}, {ENGINE_STATE_RUNNING, "ENGINE_STATE_RUNNING", "running"}, {0, NULL, NULL}};
		GType engine_state_type_id;
		engine_state_type_id = g_enum_register_static ("EngineState", values);
		g_once_init_leave (&engine_state_type_id__volatile, engine_state_type_id);
	}
	return engine_state_type_id__volatile;
}


void engine_engine_addSystem (EngineEngine* self, EngineSystem* system) {
	EngineSystemManager* _tmp0_ = NULL;
	EngineSystem* _tmp1_ = NULL;
	EngineSystem* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (system != NULL);
	_tmp0_ = self->priv->systemManager;
	_tmp1_ = system;
	engine_system_manager_addSystem (_tmp0_, _tmp1_);
	_tmp2_ = system;
	engine_system_addedToEngine (_tmp2_, self);
}


void engine_engine_removeSystem (EngineEngine* self, EngineSystem* system) {
	EngineSystemManager* _tmp0_ = NULL;
	EngineSystem* _tmp1_ = NULL;
	EngineSystem* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (system != NULL);
	_tmp0_ = self->priv->systemManager;
	_tmp1_ = system;
	engine_system_manager_removeSystem (_tmp0_, _tmp1_);
	_tmp2_ = system;
	engine_system_removedFromEngine (_tmp2_, self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void engine_engine_update (EngineEngine* self) {
	GeeList* systems = NULL;
	EngineSystemManager* _tmp0_ = NULL;
	GeeList* _tmp1_ = NULL;
	gboolean _tmp21_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->systemManager;
	_tmp1_ = engine_system_manager_getSystems (_tmp0_);
	systems = _tmp1_;
	{
		GeeList* _system_list = NULL;
		GeeList* _tmp2_ = NULL;
		GeeList* _tmp3_ = NULL;
		gint _system_size = 0;
		GeeList* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gint _system_index = 0;
		_tmp2_ = systems;
		_tmp3_ = _g_object_ref0 (_tmp2_);
		_system_list = _tmp3_;
		_tmp4_ = _system_list;
		_tmp5_ = gee_collection_get_size ((GeeCollection*) _tmp4_);
		_tmp6_ = _tmp5_;
		_system_size = _tmp6_;
		_system_index = -1;
		while (TRUE) {
			gint _tmp7_ = 0;
			gint _tmp8_ = 0;
			gint _tmp9_ = 0;
			EngineSystem* system = NULL;
			GeeList* _tmp10_ = NULL;
			gint _tmp11_ = 0;
			gpointer _tmp12_ = NULL;
			gboolean _tmp13_ = FALSE;
			EngineSystem* _tmp14_ = NULL;
			GType _tmp15_ = 0UL;
			gboolean _tmp16_ = FALSE;
			_tmp7_ = _system_index;
			_system_index = _tmp7_ + 1;
			_tmp8_ = _system_index;
			_tmp9_ = _system_size;
			if (!(_tmp8_ < _tmp9_)) {
				break;
			}
			_tmp10_ = _system_list;
			_tmp11_ = _system_index;
			_tmp12_ = gee_list_get (_tmp10_, _tmp11_);
			system = (EngineSystem*) _tmp12_;
			_tmp14_ = system;
			_tmp15_ = G_TYPE_FROM_INSTANCE ((GObject*) _tmp14_);
			_tmp16_ = g_type_is_a (_tmp15_, ENGINE_TYPE_ENTITY_SYSTEM);
			if (_tmp16_) {
				gboolean _tmp17_ = FALSE;
				_tmp17_ = self->priv->update_entities;
				_tmp13_ = _tmp17_;
			} else {
				_tmp13_ = FALSE;
			}
			if (_tmp13_) {
				EngineEntitySystem* s = NULL;
				EngineSystem* _tmp18_ = NULL;
				EngineEntitySystem* _tmp19_ = NULL;
				EngineEntitySystem* _tmp20_ = NULL;
				_tmp18_ = system;
				_tmp19_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, ENGINE_TYPE_ENTITY_SYSTEM) ? ((EngineEntitySystem*) _tmp18_) : NULL);
				s = _tmp19_;
				_tmp20_ = s;
				engine_entity_system_updateEntities (_tmp20_);
				_g_object_unref0 (s);
			}
			_g_object_unref0 (system);
		}
		_g_object_unref0 (_system_list);
	}
	_tmp21_ = self->priv->update_entities;
	if (_tmp21_) {
		self->priv->update_entities = FALSE;
	}
	{
		GeeList* _system_list = NULL;
		GeeList* _tmp22_ = NULL;
		GeeList* _tmp23_ = NULL;
		gint _system_size = 0;
		GeeList* _tmp24_ = NULL;
		gint _tmp25_ = 0;
		gint _tmp26_ = 0;
		gint _system_index = 0;
		_tmp22_ = systems;
		_tmp23_ = _g_object_ref0 (_tmp22_);
		_system_list = _tmp23_;
		_tmp24_ = _system_list;
		_tmp25_ = gee_collection_get_size ((GeeCollection*) _tmp24_);
		_tmp26_ = _tmp25_;
		_system_size = _tmp26_;
		_system_index = -1;
		while (TRUE) {
			gint _tmp27_ = 0;
			gint _tmp28_ = 0;
			gint _tmp29_ = 0;
			EngineSystem* system = NULL;
			GeeList* _tmp30_ = NULL;
			gint _tmp31_ = 0;
			gpointer _tmp32_ = NULL;
			EngineSystem* _tmp33_ = NULL;
			_tmp27_ = _system_index;
			_system_index = _tmp27_ + 1;
			_tmp28_ = _system_index;
			_tmp29_ = _system_size;
			if (!(_tmp28_ < _tmp29_)) {
				break;
			}
			_tmp30_ = _system_list;
			_tmp31_ = _system_index;
			_tmp32_ = gee_list_get (_tmp30_, _tmp31_);
			system = (EngineSystem*) _tmp32_;
			_tmp33_ = system;
			engine_system_update (_tmp33_, 0.f);
			_g_object_unref0 (system);
		}
		_g_object_unref0 (_system_list);
	}
	_g_object_unref0 (systems);
}


GeeList* engine_engine_getEntitiesFor (EngineEngine* self, GeeList* componenttypes) {
	GeeList* result = NULL;
	EngineEntityManager* _tmp0_ = NULL;
	GeeList* _tmp1_ = NULL;
	GeeList* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (componenttypes != NULL, NULL);
	_tmp0_ = self->priv->entityManager;
	_tmp1_ = componenttypes;
	_tmp2_ = engine_entity_manager_getEntitiesFor (_tmp0_, _tmp1_);
	result = _tmp2_;
	return result;
}


EngineEntity* engine_engine_createEntity (EngineEngine* self) {
	EngineEntity* result = NULL;
	EngineEntity* e = NULL;
	EngineEntity* _tmp0_ = NULL;
	EngineEntityManager* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = engine_entity_new ();
	e = _tmp0_;
	_tmp1_ = self->priv->entityManager;
	engine_entity_manager_addEntity (_tmp1_, e);
	self->priv->update_entities = TRUE;
	result = e;
	return result;
}


void engine_engine_removeEntity (EngineEngine* self, EngineEntity* e) {
	EngineEntityManager* _tmp0_ = NULL;
	EngineEntity* _tmp1_ = NULL;
	GeeList* systems = NULL;
	EngineSystemManager* _tmp2_ = NULL;
	GeeList* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (e != NULL);
	_tmp0_ = self->priv->entityManager;
	_tmp1_ = e;
	engine_entity_manager_removeEntity (_tmp0_, _tmp1_);
	_tmp2_ = self->priv->systemManager;
	_tmp3_ = engine_system_manager_getSystems (_tmp2_);
	systems = _tmp3_;
	{
		GeeList* _system_list = NULL;
		GeeList* _tmp4_ = NULL;
		GeeList* _tmp5_ = NULL;
		gint _system_size = 0;
		GeeList* _tmp6_ = NULL;
		gint _tmp7_ = 0;
		gint _tmp8_ = 0;
		gint _system_index = 0;
		_tmp4_ = systems;
		_tmp5_ = _g_object_ref0 (_tmp4_);
		_system_list = _tmp5_;
		_tmp6_ = _system_list;
		_tmp7_ = gee_collection_get_size ((GeeCollection*) _tmp6_);
		_tmp8_ = _tmp7_;
		_system_size = _tmp8_;
		_system_index = -1;
		while (TRUE) {
			gint _tmp9_ = 0;
			gint _tmp10_ = 0;
			gint _tmp11_ = 0;
			EngineSystem* system = NULL;
			GeeList* _tmp12_ = NULL;
			gint _tmp13_ = 0;
			gpointer _tmp14_ = NULL;
			EngineSystem* _tmp15_ = NULL;
			GType _tmp16_ = 0UL;
			gboolean _tmp17_ = FALSE;
			_tmp9_ = _system_index;
			_system_index = _tmp9_ + 1;
			_tmp10_ = _system_index;
			_tmp11_ = _system_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _system_list;
			_tmp13_ = _system_index;
			_tmp14_ = gee_list_get (_tmp12_, _tmp13_);
			system = (EngineSystem*) _tmp14_;
			_tmp15_ = system;
			_tmp16_ = G_TYPE_FROM_INSTANCE ((GObject*) _tmp15_);
			_tmp17_ = g_type_is_a (_tmp16_, ENGINE_TYPE_ENTITY_SYSTEM);
			if (_tmp17_) {
				EngineEntitySystem* s = NULL;
				EngineSystem* _tmp18_ = NULL;
				EngineEntitySystem* _tmp19_ = NULL;
				EngineEntitySystem* _tmp20_ = NULL;
				_tmp18_ = system;
				_tmp19_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, ENGINE_TYPE_ENTITY_SYSTEM) ? ((EngineEntitySystem*) _tmp18_) : NULL);
				s = _tmp19_;
				_tmp20_ = s;
				engine_entity_system_updateEntities (_tmp20_);
				_g_object_unref0 (s);
			}
			_g_object_unref0 (system);
		}
		_g_object_unref0 (_system_list);
	}
	_g_object_unref0 (systems);
}


EngineEngine* engine_engine_construct (GType object_type) {
	EngineEngine* self = NULL;
	self = (EngineEngine*) g_type_create_instance (object_type);
	return self;
}


EngineEngine* engine_engine_new (void) {
	return engine_engine_construct (ENGINE_TYPE_ENGINE);
}


static void engine_value_engine_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void engine_value_engine_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		engine_engine_unref (value->data[0].v_pointer);
	}
}


static void engine_value_engine_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = engine_engine_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer engine_value_engine_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* engine_value_engine_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		EngineEngine* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = engine_engine_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* engine_value_engine_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	EngineEngine** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = engine_engine_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* engine_param_spec_engine (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	EngineParamSpecEngine* spec;
	g_return_val_if_fail (g_type_is_a (object_type, ENGINE_TYPE_ENGINE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer engine_value_get_engine (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ENGINE_TYPE_ENGINE), NULL);
	return value->data[0].v_pointer;
}


void engine_value_set_engine (GValue* value, gpointer v_object) {
	EngineEngine* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ENGINE_TYPE_ENGINE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, ENGINE_TYPE_ENGINE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		engine_engine_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		engine_engine_unref (old);
	}
}


void engine_value_take_engine (GValue* value, gpointer v_object) {
	EngineEngine* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, ENGINE_TYPE_ENGINE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, ENGINE_TYPE_ENGINE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		engine_engine_unref (old);
	}
}


static void engine_engine_class_init (EngineEngineClass * klass) {
	engine_engine_parent_class = g_type_class_peek_parent (klass);
	((EngineEngineClass *) klass)->finalize = engine_engine_finalize;
	g_type_class_add_private (klass, sizeof (EngineEnginePrivate));
}


static void engine_engine_instance_init (EngineEngine * self) {
	EngineSystemManager* _tmp0_ = NULL;
	EngineEntityManager* _tmp1_ = NULL;
	self->priv = ENGINE_ENGINE_GET_PRIVATE (self);
	_tmp0_ = engine_system_manager_new ();
	self->priv->systemManager = _tmp0_;
	_tmp1_ = engine_entity_manager_new ();
	self->priv->entityManager = _tmp1_;
	self->state = ENGINE_STATE_RUNNING;
	self->priv->update_entities = FALSE;
	self->ref_count = 1;
}


static void engine_engine_finalize (EngineEngine* obj) {
	EngineEngine * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ENGINE_TYPE_ENGINE, EngineEngine);
	g_signal_handlers_destroy (self);
	_engine_system_manager_unref0 (self->priv->systemManager);
	_engine_entity_manager_unref0 (self->priv->entityManager);
}


GType engine_engine_get_type (void) {
	static volatile gsize engine_engine_type_id__volatile = 0;
	if (g_once_init_enter (&engine_engine_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { engine_value_engine_init, engine_value_engine_free_value, engine_value_engine_copy_value, engine_value_engine_peek_pointer, "p", engine_value_engine_collect_value, "p", engine_value_engine_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (EngineEngineClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) engine_engine_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (EngineEngine), 0, (GInstanceInitFunc) engine_engine_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType engine_engine_type_id;
		engine_engine_type_id = g_type_register_fundamental (g_type_fundamental_next (), "EngineEngine", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&engine_engine_type_id__volatile, engine_engine_type_id);
	}
	return engine_engine_type_id__volatile;
}


gpointer engine_engine_ref (gpointer instance) {
	EngineEngine* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void engine_engine_unref (gpointer instance) {
	EngineEngine* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		ENGINE_ENGINE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



