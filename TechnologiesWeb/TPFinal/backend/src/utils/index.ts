import { readdirSync } from 'fs';

export function readTextFilesRecursively(directoryPath: string): string[] {
  const files: string[] = [];
  const entries = readdirSync(directoryPath, { withFileTypes: true });

  for (const entry of entries) {
    const fullPath = `${directoryPath}/${entry.name}`;

    if (entry.isDirectory()) {
      files.push(...readTextFilesRecursively(fullPath));
    } else if (entry.isFile() && entry.name.endsWith('.txt')) {
      files.push(fullPath);
    }
  }

  return files;
}
