#ifndef ERT_CONFIG_KEYS_H
#define ERT_CONFIG_KEYS_H

/* These keys are used as options in KEY:VALUE statements */
#define BASE_SURFACE_KEY "BASE_SURFACE"
#define DEFINE_KEY "DEFINE"
#define FORWARD_INIT_KEY "FORWARD_INIT"
#define GENERAL_KEY "GENERAL"
#define INCLUDE_KEY "INCLUDE"
#define INIT_FILES_KEY "INIT_FILES"
#define INIT_TRANSFORM_KEY "INIT_TRANSFORM"
#define INPUT_FORMAT_KEY "INPUT_FORMAT"
#define INPUT_TRANSFORM_KEY "INPUT_TRANSFORM"
#define MAX_KEY "MAX"
#define MIN_KEY "MIN"
#define OUTPUT_FILE_KEY "OUTPUT_FILE"
#define OUTPUT_TRANSFORM_KEY "OUTPUT_TRANSFORM"
#define PARAMETER_KEY "PARAMETER"
#define REPORT_STEPS_KEY "REPORT_STEPS"
#define RESULT_FILE_KEY "RESULT_FILE"
#define TEMPLATE_KEY "TEMPLATE"
#define PRED_KEY "PRED_KEY"

#define ANALYSIS_COPY_KEY "ANALYSIS_COPY"
#define ANALYSIS_SET_VAR_KEY "ANALYSIS_SET_VAR"
#define ANALYSIS_SELECT_KEY "ANALYSIS_SELECT"
#define DATA_ROOT_KEY "DATA_ROOT"
#define DATA_FILE_KEY "DATA_FILE"
#define DATA_KW_KEY "DATA_KW"
#define ECLBASE_KEY "ECLBASE"
#define ENKF_ALPHA_KEY "ENKF_ALPHA"
#define ENKF_RERUN_KEY "ENKF_RERUN"
#define ENSPATH_KEY "ENSPATH"
#define ITER_CASE_KEY "ITER_CASE"
#define ITER_COUNT_KEY "ITER_COUNT"
#define ITER_RETRY_COUNT_KEY "ITER_RETRY_COUNT"
#define FIELD_KEY "FIELD"
#define FORWARD_MODEL_KEY "FORWARD_MODEL"
#define GEN_DATA_KEY "GEN_DATA"
#define GEN_KW_KEY "GEN_KW"
#define GEN_KW_TAG_FORMAT_KEY "GEN_KW_TAG_FORMAT"
#define GEN_KW_EXPORT_NAME_KEY "GEN_KW_EXPORT_NAME"
#define GRID_KEY "GRID"
#define HISTORY_SOURCE_KEY "HISTORY_SOURCE"
#define INSTALL_JOB_KEY "INSTALL_JOB"
#define INSTALL_JOB_DIRECTORY_KEY "INSTALL_JOB_DIRECTORY"
#define JOB_SCRIPT_KEY "JOB_SCRIPT"
#define JOBNAME_KEY "JOBNAME"
#define LICENSE_PATH_KEY "LICENSE_PATH"
#define MAX_RESAMPLE_KEY "MAX_RESAMPLE"
#define MAX_SUBMIT_KEY "MAX_SUBMIT"
#define NUM_REALIZATIONS_KEY "NUM_REALIZATIONS"
#define MIN_REALIZATIONS_KEY "MIN_REALIZATIONS"
#define OBS_CONFIG_KEY "OBS_CONFIG"
#define QUEUE_SYSTEM_KEY "QUEUE_SYSTEM"
#define QUEUE_OPTION_KEY "QUEUE_OPTION"
#define HOOK_WORKFLOW_KEY "HOOK_WORKFLOW"
#define REFCASE_KEY "REFCASE"
#define RERUN_START_KEY "RERUN_START"
#define RUNPATH_FILE_KEY "RUNPATH_FILE"
#define RUNPATH_KEY "RUNPATH"
#define RUN_TEMPLATE_KEY "RUN_TEMPLATE"
#define SCHEDULE_PREDICTION_FILE_KEY "SCHEDULE_PREDICTION_FILE"
#define SETENV_KEY "SETENV"
#define SIMULATION_JOB_KEY "SIMULATION_JOB"
#define STD_CUTOFF_KEY "STD_CUTOFF"
#define SUMMARY_KEY "SUMMARY"
#define SURFACE_KEY "SURFACE"
#define UPDATE_LOG_PATH_KEY "UPDATE_LOG_PATH"
#define UPDATE_PATH_KEY "UPDATE_PATH"
#define RANDOM_SEED_KEY "RANDOM_SEED"
#define WORKFLOW_JOB_DIRECTORY_KEY "WORKFLOW_JOB_DIRECTORY"
#define LOAD_WORKFLOW_KEY "LOAD_WORKFLOW"
#define LOAD_WORKFLOW_JOB_KEY "LOAD_WORKFLOW_JOB"
#define RUN_MODE_PRE_SIMULATION_NAME "PRE_SIMULATION"
#define RUN_MODE_POST_SIMULATION_NAME "POST_SIMULATION"
#define RUN_MODE_PRE_UPDATE_NAME "PRE_UPDATE"
#define RUN_MODE_POST_UPDATE_NAME "POST_UPDATE"
#define RUN_MODE_PRE_FIRST_UPDATE_NAME "PRE_FIRST_UPDATE"
#define STOP_LONG_RUNNING_KEY "STOP_LONG_RUNNING"
#define MAX_RUNTIME_KEY "MAX_RUNTIME"
#define TIME_MAP_KEY "TIME_MAP"
#define UPDATE_SETTING_KEY "UPDATE_SETTINGS"
#define NUM_CPU_KEY "NUM_CPU"

#define CONFIG_DIRECTORY_KEY "CONFIG_DIRECTORY"

#define SLURM_SBATCH_OPTION "SBATCH"
#define SLURM_SCANCEL_OPTION "SCANCEL"
#define SLURM_SCONTROL_OPTION "SCONTROL"
#define SLURM_SQUEUE_OPTION "SQUEUE"
#define SLURM_PARTITION_OPTION "PARTITION"
#define SLURM_SQUEUE_TIMEOUT_OPTION "SQUEUE_TIMEOUT"

// Observe that the SLURM_MAX_RUNTIME_OPTION expects a time limit in seconds,
// whereas slurm uses a time limit in minutes
#define SLURM_MAX_RUNTIME_OPTION "MAX_RUNTIME"
#define SLURM_MEMORY_OPTION "MEMORY"
#define SLURM_MEMORY_PER_CPU_OPTION "MEMORY_PER_CPU"

// For the EXCLUDE and INCLUDE host options the slurm driver
// maintains an internal list of hostnames, and the option can be called
// repeatedly. It is possible to add multiple hosts separated by space or comma
// in one option call:
//
// QUEUE_OPTION SLURM EXCLUDE_HOST host1,host2,host3
// QUEUE_OPTION SLURM EXCLUDE_HOST host5 host6,host7
#define SLURM_EXCLUDE_HOST_OPTION "EXCLUDE_HOST"
#define SLURM_INCLUDE_HOST_OPTION "INCLUDE_HOST"

#endif
