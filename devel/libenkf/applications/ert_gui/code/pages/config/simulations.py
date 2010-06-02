# ----------------------------------------------------------------------------------------------
# Simulations tab
# ----------------------------------------------------------------------------------------------
from PyQt4 import QtCore
from widgets.spinnerwidgets import IntegerSpinner
import ertwrapper
from widgets.tablewidgets import KeywordTable, MultiColumnTable, MultiColumnTable
from widgets.pathchooser import PathChooser
from widgets.checkbox import CheckBox
from widgets.configpanel import ConfigPanel
from widgets.stringbox import StringBox
from pages.config.jobs.forwardmodelpanel import ForwardModelPanel

def createSimulationsPage(configPanel, parent):
    configPanel.startPage("Simulations")


    r = configPanel.addRow(IntegerSpinner(parent, "Max submit", "max_submit", 1, 10000))
    r.initialize = lambda ert : [ert.setTypes("site_config_get_max_submit", ertwrapper.c_int),
                                 ert.setTypes("site_config_set_max_submit", None, [ertwrapper.c_int])]
    r.getter = lambda ert : ert.enkf.site_config_get_max_submit(ert.site_config)
    r.setter = lambda ert, value : ert.enkf.site_config_set_max_submit(ert.site_config, value)

    r = configPanel.addRow(IntegerSpinner(parent, "Max resample", "max_resample", 1, 10000))
    r.initialize = lambda ert : [ert.setTypes("model_config_get_max_resample", ertwrapper.c_int),
                                 ert.setTypes("model_config_set_max_resample", None, [ertwrapper.c_int])]
    r.getter = lambda ert : ert.enkf.model_config_get_max_resample(ert.model_config)
    r.setter = lambda ert, value : ert.enkf.model_config_set_max_resample(ert.model_config, value)

    r = configPanel.addRow(ForwardModelPanel(parent))
    def dummy(model):
        print "Missing"
    r.getter = dummy
    def dummy_set(model, value):
        print "mioisng"
    r.setter = dummy_set

#    r = configPanel.addRow(KeywordTable(parent, "Forward model", "forward_model", "Job", "Arguments"))
#    r.getter = lambda ert : ert.getAttribute("forward_model")
#    r.setter = lambda ert, value : ert.setAttribute("forward_model", value)

    r = configPanel.addRow(PathChooser(parent, "Case table", "case_table"))
    r.getter = lambda ert : ert.getAttribute("case_table")
    r.setter = lambda ert, value : ert.setAttribute("case_table", value)

    r = configPanel.addRow(PathChooser(parent, "License path", "license_path"))
    r.initialize = lambda ert : [ert.setTypes("site_config_get_license_root_path__", ertwrapper.c_char_p),
                                 ert.setTypes("site_config_set_license_root_path", None, ertwrapper.c_char_p)]
    r.getter = lambda ert : ert.enkf.site_config_get_license_root_path__(ert.site_config)

    def ls(string):
        if string is None:
            return ""
        else:
            return string

    r.setter = lambda ert, value : ert.enkf.site_config_set_license_root_path(ert.site_config, ls(value))



    internalPanel = ConfigPanel(parent)

    internalPanel.startPage("Runpath")

    r = internalPanel.addRow(PathChooser(parent, "Runpath", "runpath", path_format=True))
    r.initialize = lambda ert : [ert.setTypes("model_config_get_runpath_as_char", ertwrapper.c_char_p),
                                 ert.setTypes("model_config_set_runpath_fmt", None, [ertwrapper.c_char_p])]
    r.getter = lambda ert : ert.enkf.model_config_get_runpath_as_char(ert.model_config)
    r.setter = lambda ert, value : ert.enkf.model_config_set_runpath_fmt(ert.model_config, str(value))
    parent.connect(r, QtCore.SIGNAL("contentsChanged()"), lambda : r.modelEmit("runpathChanged()"))

    r = internalPanel.addRow(CheckBox(parent, "Pre clear", "pre_clear_runpath", "Perform pre clear"))
    r.getter = lambda ert : ert.getAttribute("pre_clear_runpath")
    r.setter = lambda ert, value : ert.setAttribute("pre_clear_runpath", value)

    r = internalPanel.addRow(StringBox(parent, "Delete", "delete_runpath"))
    r.getter = lambda ert : ert.getAttribute("delete_runpath")
    r.setter = lambda ert, value : ert.setAttribute("delete_runpath", value)

    r = internalPanel.addRow(StringBox(parent, "Keep", "keep_runpath"))
    r.getter = lambda ert : ert.getAttribute("keep_runpath")
    r.setter = lambda ert, value : ert.setAttribute("keep_runpath", value)

    internalPanel.endPage()

    internalPanel.startPage("Run Template")

    r = internalPanel.addRow(MultiColumnTable(parent, "", "run_template", ["Template", "Target file", "Arguments"]))
    r.getter = lambda ert : ert.getAttribute("run_template")
    r.setter = lambda ert, value : ert.setAttribute("run_template", value)

    #r = internalPanel.addRow(PathChooser(widget, "Template", "run_template", True))
    #r.getter = lambda ert : ert.getAttribute("run_template")
    #r.setter = lambda ert, value : ert.setAttribute("run_template", value)
    #
    #r = internalPanel.addRow(PathChooser(widget, "Target file", "target_file", True))
    #r.getter = lambda ert : ert.getAttribute("target_file")
    #r.setter = lambda ert, value : ert.setAttribute("target_file", value)
    #
    #r = internalPanel.addRow(KeywordTable(widget, "Arguments", "template_arguments"))
    #r.getter = lambda ert : ert.getAttribute("template_arguments")
    #r.setter = lambda ert, value : ert.setAttribute("template_arguments", value)

    internalPanel.endPage()
    configPanel.addRow(internalPanel)


    configPanel.endPage()
