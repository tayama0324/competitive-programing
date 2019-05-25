;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  ruby-mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;(autoload 'ruby-mode "ruby-mode"
;  "Mode for editing ruby source files" t)
;(setq auto-mode-alist
;      (append '(("\\.rb$" . ruby-mode)) auto-mode-alist))
;(setq interpreter-mode-alist (append '(("ruby" . ruby-mode))
;                                     interpreter-mode-alist))
;(autoload 'run-ruby "inf-ruby"
;  "Run an inferior Ruby process")
;(autoload 'inf-ruby-keys "inf-ruby"
;  "Set local key defs for inf-ruby in ruby-mode")
;(add-hook 'ruby-mode-hook
;          '(lambda ()
;            (inf-ruby-keys)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  python-mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(add-hook 'python-mode-hook
      '(lambda()
         (setq indent-level 4)
         (setq python-indent 4)
         (setq tab-width 4)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  flycheck
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(require 'package)

(add-to-list 'package-archives
             '("MELPA Stable" . "http://stable.melpa.org/packages/") t)
(package-initialize)
(package-refresh-contents)

(package-install 'flycheck)

(global-flycheck-mode)

(package-install 'exec-path-from-shell)
(exec-path-from-shell-initialize)

(global-set-key "\C-x\C-n" 'flycheck-next-error)
(global-set-key "\C-x\C-p" 'flycheck-previous-error)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  terminal
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(global-set-key "\C-t" '(lambda()
                          (interactive)
                          (if (get-buffer "*ansi-term*")
                              (switch-to-buffer "*ansi-term*")
                            (ansi-term "bash"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  ibuffer
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(require 'ibuf-ext)

(global-set-key "\C-x\C-b" 'ibuffer)
(setq ibuffer-default-sorting-mode 'major-mode)
(setq ibuffer-never-show-regexps '("messages"))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  font
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(add-to-list 'default-frame-alist '(font . "fontset-default"))
;; (set-frame-font "fontset-default")

(set-face-attribute 'default nil
                    :family "Ricty" 
                    :height 110
                    )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  misc
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(setq-default indent-tabs-mode nil)

