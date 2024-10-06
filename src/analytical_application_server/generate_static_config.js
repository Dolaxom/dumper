require('dotenv').config();
const fs = require('fs');
const yaml = require('js-yaml');

const config = {
    components_manager: {
        task_processors: {
            'main-task-processor': {
                worker_threads: 4,
            },
            'fs-task-processor': {
                worker_threads: 1,
            },
        },
        default_task_processor: 'main-task-processor',
        components: {
            server: {
                listener: {
                    port: 8015,
                    task_processor: 'main-task-processor',
                },
            },
            logging: {
                'fs-task-processor': 'fs-task-processor',
                loggers: {
                    default: {
                        file_path: '@stderr',
                        level: 'debug',
                        overflow_behavior: 'discard',
                    },
                },
            },
            'handler-message': {
                path: '/api/v1/message',
                method: 'GET,POST',
                task_processor: 'main-task-processor',
            },
        },
    },
};

// Запись конфигурации в YAML файл
fs.writeFileSync('static_config_gen.yaml', yaml.dump(config));
